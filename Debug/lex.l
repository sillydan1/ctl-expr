
/*
MIT License

Copyright (c) 2022 Asger Gitz-Johansen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

%{
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring> // strerror
#include <string>
#include <sstream>
#include "ctl_driver.h"
#include "ctl_parser.hpp"
%}



%{
#if defined __clang__
# define CLANG_VERSION (__clang_major__ * 100 + __clang_minor__)
#endif

// Clang and ICC like to pretend they are GCC.
#if defined __GNUC__ && !defined __clang__ && !defined __ICC
# define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 6.4.0, 7.3.0 with -O3.
#if defined GCC_VERSION && 600 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// This example uses Flex's C back end, yet compiles it as C++.
// So expect warnings about C style casts and NULL.
#if defined CLANG_VERSION && 500 <= CLANG_VERSION
# pragma clang diagnostic ignored "-Wold-style-cast"
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined GCC_VERSION && 407 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wold-style-cast"
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

// Old versions of Flex (2.5.35) generate an incomplete documentation comment.
//
//  In file included from src/scan-code-c.c:3:
//  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
//        [-Werror,-Wdocumentation]
//   * @param line_number
//     ~~~~~~~~~~~~~~~~~^
//  1 error generated.
#if FLEX_VERSION < 206 && defined CLANG_VERSION
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

// Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
// GCC 7 and Clang 6.
#if FLEX_VERSION < 206
# if defined CLANG_VERSION && 600 <= CLANG_VERSION
#  pragma clang diagnostic ignored "-Wdeprecated-register"
# elif defined GCC_VERSION && 700 <= GCC_VERSION
#  pragma GCC diagnostic ignored "-Wregister"
# endif
#endif

#if FLEX_VERSION < 206
# if defined CLANG_VERSION
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshorten-64-to-32"
#  pragma clang diagnostic ignored "-Wsign-conversion"
# elif defined GCC_VERSION
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
# endif
#endif

// Flex 2.6.4, GCC 9
// warning: useless cast to type 'int' [-Wuseless-cast]
// 1361 |   YY_CURRENT_BUFFER_LVALUE->yy_buf_size = (int) (new_size - 2);
//      |                                                 ^
#if defined GCC_VERSION && 900 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in provided string.
  ctl ::parser::symbol_type make_NUMBER(const std::string &s, const ctl ::parser::location_type& loc);
  ctl ::parser::symbol_type make_FLOAT(const std::string &s, const ctl ::parser::location_type& loc);
  ctl ::parser::symbol_type make_STRING(const std::string &s, const ctl ::parser::location_type& loc);
  ctl ::parser::symbol_type make_BOOL(std::string s, const ctl ::parser::location_type& loc);
  ctl ::parser::symbol_type make_CLOCK(const std::string& s, const ctl ::parser::location_type& loc);
%}




%{
 // TODO: Remove [ðđ€\(\)]
%}
id     [a-z_A-Z]([.ðđ€\(\)a-zA-Z_0-9]*[a-zA-Z_0-9]+)?
int    [0-9]+[Ll]?
clk    [0-9]+(_ms)
flt    [0-9]+[.][0-9]+[fd]?
bool   [Ff]alse|[Tt]rue
str    \"(\\.|[^\\"])*\"
blank  [ \t\r]
accmod [Pp](ublic|rivate|rotected)
type   int|long|float|double|string|bool|clock|timer|var|auto

uuid [0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}
lloc [Ll][0-9]+

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION  loc.columns(yyleng);
%}

%%
%{
  // A handy shortcut to the location held by the driver.
  ctl::location& loc = drv->location;
  // Code run each time yylex is called.
  loc.step();
%}

"A" return ctl::parser::make_FORALL(loc);
"E" return ctl::parser::make_EXISTS(loc);
"F" return ctl::parser::make_FINALLY(loc);
"G" return ctl::parser::make_GLOBALLY(loc);
"X" return ctl::parser::make_NEXT(loc);
"U" return ctl::parser::make_UNTIL(loc);
"W" return ctl::parser::make_WEAK_UNTIL(loc);
{uuid} return ctl::parser::make_LOCATION(yytext, loc);
{lloc} return ctl::parser::make_LOCATION(yytext, loc);



{blank}+   loc.step();
\n+        { loc.lines(yyleng); loc.step(); }

"-"        return ctl ::parser::make_MINUS  (loc);
"+"        return ctl ::parser::make_PLUS   (loc);
"*"        return ctl ::parser::make_STAR   (loc);
"/"        return ctl ::parser::make_SLASH  (loc);
"%"        return ctl ::parser::make_PERCENT(loc);
"^"        return ctl ::parser::make_HAT    (loc);
"&&"       return ctl ::parser::make_AND    (loc);
"||"       return ctl ::parser::make_OR     (loc);
"^^"       return ctl ::parser::make_XOR    (loc);
"=>"       return ctl ::parser::make_IMPLIES(loc);
">"        return ctl ::parser::make_GT     (loc);
">="       return ctl ::parser::make_GE     (loc);
"=="       return ctl ::parser::make_EE     (loc);
"!="       return ctl ::parser::make_NE     (loc);
"<="       return ctl ::parser::make_LE     (loc);
"<"        return ctl ::parser::make_LT     (loc);
"!"        return ctl ::parser::make_NOT    (loc);
"("        return ctl ::parser::make_LPAREN (loc);
")"        return ctl ::parser::make_RPAREN (loc);
":="       return ctl ::parser::make_ASSIGN (loc);
";"        return ctl ::parser::make_TERM   (loc);

{accmod}   return ctl ::parser::make_ACCMOD(yytext, loc);
{type}     return ctl ::parser::make_TYPE(loc);

{int}      return make_NUMBER(yytext, loc);
{flt}      return make_FLOAT(yytext, loc);
{str}      return make_STRING(yytext, loc);
{clk}      return make_CLOCK(yytext, loc);
{bool}     return make_BOOL(yytext, loc);
{id}       return ctl ::parser::make_IDENTIFIER (yytext, loc);
.          { throw ctl ::parser::syntax_error(loc, "invalid character: " + std::string(yytext)); }
<<EOF>>    return ctl ::parser::make_YYEOF (loc);


%%



ctl ::parser::symbol_type make_NUMBER(const std::string &s, const ctl ::parser::location_type& loc) {
  errno = 0;
  long n = strtol (s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw ctl ::parser::syntax_error (loc, "integer is out of range: " + s);
  return ctl ::parser::make_NUMBER ((int) n, loc);
}

ctl ::parser::symbol_type make_FLOAT(const std::string &s, const ctl ::parser::location_type& loc) {
    try {
        double n = std::stod(s.c_str());
        return ctl ::parser::make_FLOAT((double)n, loc);
    } catch(std::out_of_range& e) {
        throw ctl ::parser::syntax_error (loc, "double is out of range: " + s);
    }
}

ctl ::parser::symbol_type make_STRING(const std::string &s, const ctl ::parser::location_type& loc) {
    return ctl ::parser::make_STRING(s.substr(1, s.size()-2), loc);
}

ctl ::parser::symbol_type make_BOOL(std::string s, const ctl ::parser::location_type& loc) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    bool b;
    std::istringstream(s) >> std::boolalpha >> b;
    return ctl ::parser::make_BOOL(b, loc);
}

ctl ::parser::symbol_type make_CLOCK(const std::string &s, const ctl ::parser::location_type& loc) {
    try {
        auto c = expr::stoclk(s.c_str());
        return ctl ::parser::make_CLOCK(c, loc);
    } catch(std::out_of_range& e) {
        throw ctl ::parser::syntax_error (loc, "clock value is out of range: " + s);
    }
}



void ctl::driver::scan_begin() {
    yy_flex_debug = trace_scanning;
    if(file.empty() || file == "-")
        yyin = stdin;
    else
        yy_scan_string(file.c_str());
}

void ctl::driver::scan_end() {
}


/* MIT License
 *
 * Copyright (c) 2022 Asger Gitz-Johansen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
%{
#include "ctl-parser.hpp"
#include "ctl-scanner.hpp"
#undef YY_DECL
#define YY_DECL int ctl::scanner::yylex(ctl::parser::semantic_type* const lval, ctl::parser::location_type* loc)
using token = ctl::parser::token;
#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option c++ noyywrap nodefault
%option yyclass="ctl::scanner"
%option outfile="ctl-scanner.cpp"

/* ================================================== */
id     [a-z_A-Z]([.\(\)a-zA-Z_0-9]*[a-zA-Z_0-9]+)?
int    [0-9]+[Ll]?
clk    [0-9]+(_ms)
flt    [0-9]+[.][0-9]+[fd]?
bool   [Ff]alse|[Tt]rue
str    \"(\\.|[^\\"])*\"
blank  [ \t\r]

uuid   [0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}
/* TODO: Conflicts with {id}! */
lloc   [Ll][0-9]+

%%

{blank}+   /* nothing */
\n+        /* nothing */

"A"        return token::FORALL;
"E"        return token::EXISTS;
"F"        return token::FINALLY;
"G"        return token::GLOBALLY;
"X"        return token::NEXT;
"U"        return token::UNTIL;
"W"        return token::WEAK_UNTIL;
"-"        return token::MINUS;
"+"        return token::PLUS;
"*"        return token::STAR;
"/"        return token::SLASH;
"%"        return token::PERCENT;
"^"        return token::HAT;
"&&"       return token::AND;
"||"       return token::OR;
"^^"       return token::XOR;
"=>"       return token::IMPLIES;
">"        return token::GT;
">="       return token::GE;
"=="       return token::EE;
"!="       return token::NE;
"<="       return token::LE;
"<"        return token::LT;
"!"        return token::NOT;
"("        return token::LPAREN;
")"        return token::RPAREN;
":="       return token::ASSIGN;
";"        return token::TERM;
{int}      { 
                lval->build<int>(atoi(YYText())); 
                return token::NUMBER; 
           }
{flt}      { 
                lval->build<float>(atof(YYText())); 
                return token::FLOAT; 
           }
{clk}      { 
                lval->build<expr::clock_t>(expr::stoclk(YYText())); 
                return token::CLOCK; 
           }
{bool}     { 
                lval->build<bool>(expr::stob(YYText())); 
                return token::BOOL; 
           }
{str}      { 
                std::string s{YYText()}; 
                lval->build<std::string>(s.substr(1, s.size()-2)); 
                return token::STRING; 
           }
{id}       { 
                lval->build<std::string>(std::string{YYText()}); 
                return token::IDENTIFIER; 
           }
{uuid}     {
                lval->build<std::string>(std::string{YYText()});
                return token::LOCATION;
           }
{lloc}     {
                lval->build<std::string>(std::string{YYText()});
                return token::LOCATION;
           }
<<EOF>>    return token::YYEOF;
.          throw ctl::parser::syntax_error(*loc, "invalid character: " + std::string(YYText()));

%%

/* ================================================== */


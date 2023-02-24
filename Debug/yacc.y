
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


%skeleton "lalr1.cc"
%define api.prefix {ctl}
%require "3.5"

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

// Forward declare the driver (include later)
%code requires {
    #include <string>
    #include <ctl_syntax_tree.h>
    namespace ctl { class driver; }
}

%param { ctl::driver* drv }

// Enable parser location tracking
%locations

// Enable parser tracing and detailed errors
%define parse.trace
%define parse.error verbose
// Enable full lookahead to avoid incorrect error information
// See https://www.gnu.org/software/bison/manual/html_node/LAC.html for details
%define parse.lac full

// Include the driver
%code {
    #include "ctl_driver.h"
    void ctl ::parser::error (const location_type& l, const std::string& m) {
      std::cerr << l << ": " << m << '\n';
    }
}




%define api.token.prefix {TOK_}
%token YYEOF 0
%token
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  PERCENT "%"
  HAT     "^"
  AND     "&&"
  OR      "||"
  XOR     "^^"
  IMPLIES "=>"
  GT      ">"
  GE      ">="
  EE      "=="
  NE      "!="
  LE      "<="
  LT      "<"
  NOT     "!"
  LPAREN  "("
  RPAREN  ")"
  ASSIGN  ":="
  TYPE    "type"
  TERM    ";"
;

// Identifiers are strings
%token <std::string> IDENTIFIER "identifier"
%token <std::string> ACCMOD "access_modifier"
%token <int> NUMBER "number"
%token <float> FLOAT "float"
%token <bool> BOOL "bool"
%token <expr::clock_t> CLOCK "clk"
%token <std::string> STRING "string"
%printer { yyo << $$; } <*>;

%left XOR
%left OR
%left AND
%left GT GE EE NE LE LT
%left PLUS MINUS STAR SLASH PERCENT HAT
%left IMPLIES
%precedence LPAREN NOT

%token
  FORALL     "A"
  EXISTS     "E"
  NEXT       "X"
  GLOBALLY   "G"
  FINALLY    "F"
  UNTIL      "U"
  WEAK_UNTIL "W"
;

%token <std::string> LOCATION "location"


%nterm <ctl::syntax_tree_t> query quantifier state predicate
%nterm <expr::syntax_tree_t> exp bin_op mono_op lit


%%
%start queries;
queries:
  query { drv->add_tree($1); }
;

query:
  FORALL quantifier { $$ = ctl::syntax_tree_t(ctl::modal_op_t::A).concat($2); }
| EXISTS quantifier { $$ = ctl::syntax_tree_t(ctl::modal_op_t::E).concat($2); }
;

quantifier:
  NEXT predicate                  { $$ = ctl::syntax_tree_t(ctl::quantifier_t::X).concat($2); }
| GLOBALLY predicate              { $$ = ctl::syntax_tree_t(ctl::quantifier_t::G).concat($2); }
| FINALLY predicate               { $$ = ctl::syntax_tree_t(ctl::quantifier_t::F).concat($2); }
| predicate UNTIL predicate       { $$ = ctl::syntax_tree_t(ctl::quantifier_t::U).concat($1).concat($3); }
| predicate WEAK_UNTIL predicate  { $$ = ctl::syntax_tree_t(ctl::quantifier_t::W).concat($1).concat($3); }
;

predicate:
  "(" query ")" OR "(" query ")"        { $$ = BINOP_CTOR (_or,$2,$6); }
| "(" query ")" XOR "(" query ")"       { $$ = BINOP_CTOR (_xor,$2,$6); }
| "(" query ")" IMPLIES "(" query ")"   { $$ = BINOP_CTOR (_implies,$2,$6); }
| "(" query ")" AND "(" query ")"       { $$ = BINOP_CTOR (_and,$2,$6); }
| "(" query ")"                         { $$ = $2; }
| "(" predicate ")"                     { $$ = $2; }
| state                                 { $$ = $1; }
| exp                                   { $$ = ctl::syntax_tree_t($1); }
;

state:
  "location"                { $$ = LIT_CTOR(ctl::location_t{$1}); }
;







exp:
  lit                   { $$ = $1; }
| bin_op                { $$ = $1; }
| mono_op               { $$ = $1; }
;

bin_op:
  exp PLUS exp          { $$ = EXP_BINOP_CTOR (plus,$1,$3);     }
| exp MINUS exp         { $$ = EXP_BINOP_CTOR (minus,$1,$3);    }
| exp STAR exp          { $$ = EXP_BINOP_CTOR (star,$1,$3);     }
| exp SLASH exp         { $$ = EXP_BINOP_CTOR (slash,$1,$3);    }
| exp PERCENT exp       { $$ = EXP_BINOP_CTOR (percent,$1,$3);  }
| exp HAT exp           { $$ = EXP_BINOP_CTOR (hat,$1,$3);      }
| exp GT  exp           { $$ = EXP_BINOP_CTOR (gt,$1,$3);       }
| exp GE exp            { $$ = EXP_BINOP_CTOR (ge,$1,$3);       }
| exp EE exp            { $$ = EXP_BINOP_CTOR (ee,$1,$3);       }
| exp NE exp            { $$ = EXP_BINOP_CTOR (ne,$1,$3);       }
| exp LE exp            { $$ = EXP_BINOP_CTOR (le,$1,$3);       }
| exp LT  exp           { $$ = EXP_BINOP_CTOR (lt,$1,$3);       }
| exp OR exp            { $$ = EXP_BINOP_CTOR (_or,$1,$3);      }
| exp XOR exp           { $$ = EXP_BINOP_CTOR (_xor,$1,$3);     }
| exp IMPLIES exp       { $$ = EXP_BINOP_CTOR (_implies,$1,$3); }
| exp AND exp           { $$ = EXP_BINOP_CTOR (_and,$1,$3);     }
;

mono_op:
  NOT exp               { $$ = EXP_MONOOP_CTOR (_not,$2);        }
| LPAREN exp RPAREN     { $$ = EXP_MONOOP_CTOR (parentheses,$2); }
;

lit:
  "number"              { $$ = EXP_LIT_CTOR ($1);   }
| MINUS "number"        { $$ = EXP_LIT_CTOR (-$2);  }
| "float"               { $$ = EXP_LIT_CTOR ($1);   }
| MINUS "float"         { $$ = EXP_LIT_CTOR (-$2);  }
| "string"              { $$ = EXP_LIT_CTOR ($1);   }
| "bool"                { $$ = EXP_LIT_CTOR ($1);   }
| "identifier"          { $$ = EXP_IDENT_CTOR ($1); }
| "clk"                 { $$ = EXP_LIT_CTOR ($1);   }
;






%%

%skeleton "lalr1.cc"
%require "3.2"
%defines "ctl-parser.hpp"
%output "ctl-parser.cpp"
%define api.parser.class { parser }
%define api.namespace { ctl }
%define api.value.type variant
%define parse.assert
%locations

%code requires {
    #include <memory>
    #include "symbol_table.h"
    #include "ast-factory.h"
    #include "language-builder.h"

    namespace ctl {
        class scanner;
        struct parser_args {
            scanner* scn;
            ast_factory* fct;
            language_builder* builder;
        };
    }
}

%parse-param { parser_args& args }

%code {
    #include <iostream>
    #include "ctl-scanner.hpp"
    #undef yylex
    #define yylex args.scn->yylex
}

/* ================================================== */
%token YYEOF 0
%token MINUS PLUS STAR SLASH PERCENT HAT AND OR XOR IMPLIES GT GE EE NE LE LT NOT LPAREN RPAREN ASSIGN TERM
%token FORALL EXISTS FINALLY GLOBALLY NEXT UNTIL WEAK_UNTIL
%token <std::string> IDENTIFIER LOCATION
%token <int> NUMBER
%token <float> FLOAT
%token <bool> BOOL
%token <std::string> STRING 
%token <expr::clock_t> CLOCK
%nterm <syntax_tree_t> query quantifier predicate exp bin_op mono_op lit

%left XOR
%left OR
%left AND
%left GT GE EE NE LE LT
%left PLUS MINUS STAR SLASH PERCENT HAT
%left IMPLIES
%precedence LPAREN NOT

%%

%start unit;

unit:
  %empty            { }
| queries           { }
| queries TERM unit { }
;

queries:
  query             { args.builder->add_query(args.fct->build_root($1)); }
;

query:
  FORALL quantifier { $$ = args.fct->build_modal (ctl::modal_op_t::A, $2); } 
| EXISTS quantifier { $$ = args.fct->build_modal (ctl::modal_op_t::E, $2); }
;

quantifier:
  NEXT predicate                  { $$ = args.fct->build_quantifier (quantifier_op_t::X, $2); }
| GLOBALLY predicate              { $$ = args.fct->build_quantifier (quantifier_op_t::G, $2); }
| FINALLY predicate               { $$ = args.fct->build_quantifier (quantifier_op_t::F, $2); }
| predicate UNTIL predicate       { $$ = args.fct->build_quantifier (quantifier_op_t::U, $1, $3); }
| predicate WEAK_UNTIL predicate  { $$ = args.fct->build_quantifier (quantifier_op_t::W, $1, $3); }
;

predicate:
  LPAREN query RPAREN OR LPAREN query RPAREN        { $$ = args.fct->build_operator (expr::operator_type_t::_or,$2,$6); }
| LPAREN query RPAREN XOR LPAREN query RPAREN       { $$ = args.fct->build_operator (expr::operator_type_t::_xor,$2,$6); }
| LPAREN query RPAREN IMPLIES LPAREN query RPAREN   { $$ = args.fct->build_operator (expr::operator_type_t::_implies,$2,$6); }
| LPAREN query RPAREN AND LPAREN query RPAREN       { $$ = args.fct->build_operator (expr::operator_type_t::_and,$2,$6); }
| LPAREN query RPAREN                               { $$ = args.fct->build_operator (expr::operator_type_t::parentheses, $2); }
| LPAREN predicate RPAREN                           { $$ = args.fct->build_operator (expr::operator_type_t::parentheses, $2); }
| exp                                               { $$ = $1; }
;

exp:
  lit                   { $$ = $1; }
| bin_op                { $$ = $1; }
| mono_op               { $$ = $1; }
;

bin_op:
  exp PLUS exp          { $$ = args.fct->build_operator (expr::operator_type_t::plus,$1,$3); }
| exp MINUS exp         { $$ = args.fct->build_operator (expr::operator_type_t::minus,$1,$3); }
| exp STAR exp          { $$ = args.fct->build_operator (expr::operator_type_t::star,$1,$3); }
| exp SLASH exp         { $$ = args.fct->build_operator (expr::operator_type_t::slash,$1,$3); }
| exp PERCENT exp       { $$ = args.fct->build_operator (expr::operator_type_t::percent,$1,$3); }
| exp HAT exp           { $$ = args.fct->build_operator (expr::operator_type_t::hat,$1,$3); }
| exp GT  exp           { $$ = args.fct->build_operator (expr::operator_type_t::gt,$1,$3); }
| exp GE exp            { $$ = args.fct->build_operator (expr::operator_type_t::ge,$1,$3); }
| exp EE exp            { $$ = args.fct->build_operator (expr::operator_type_t::ee,$1,$3); }
| exp NE exp            { $$ = args.fct->build_operator (expr::operator_type_t::ne,$1,$3); }
| exp LE exp            { $$ = args.fct->build_operator (expr::operator_type_t::le,$1,$3); }
| exp LT  exp           { $$ = args.fct->build_operator (expr::operator_type_t::lt,$1,$3); }
| exp OR exp            { $$ = args.fct->build_operator (expr::operator_type_t::_or,$1,$3); }
| exp XOR exp           { $$ = args.fct->build_operator (expr::operator_type_t::_xor,$1,$3); }
| exp IMPLIES exp       { $$ = args.fct->build_operator (expr::operator_type_t::_implies,$1,$3); }
| exp AND exp           { $$ = args.fct->build_operator (expr::operator_type_t::_and,$1,$3); }
;

mono_op:
  NOT exp               { $$ = args.fct->build_operator (expr::operator_type_t::_not,$2); }
| LPAREN exp RPAREN     { $$ = args.fct->build_operator (expr::operator_type_t::parentheses,$2); }
;

lit:
  NUMBER                { $$ = args.fct->build_literal ($1); }
| MINUS NUMBER          { $$ = args.fct->build_literal (-$2); }
| FLOAT                 { $$ = args.fct->build_literal ($1); }
| MINUS FLOAT           { $$ = args.fct->build_literal (-$2); }
| STRING                { $$ = args.fct->build_literal ($1); }
| BOOL                  { $$ = args.fct->build_literal ($1); }
| CLOCK                 { $$ = args.fct->build_literal ($1); }
| IDENTIFIER            { $$ = args.fct->build_identifier ($1); }
| LOCATION              { $$ = args.fct->build_location ($1); }
;

%%
/* ================================================== */

void ctl::parser::error(const location_type& l, const std::string& msg) {
    std::cerr << msg << " at " << l << "\n";
}

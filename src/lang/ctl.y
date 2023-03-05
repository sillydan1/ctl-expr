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
            expr::ast_factory* fct;
            expr::language_builder* builder;
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
%%

%%
/* ================================================== */


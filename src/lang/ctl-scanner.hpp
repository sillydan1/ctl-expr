#ifndef CTL_SCANNER_HPP
#define CTL_SCANNER_HPP
#include "ast-factory.h"

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "ctl-parser.hpp"
#include "location.hh"

namespace ctl {
    class scanner : public yyFlexLexer {
    public:
        scanner(std::istream& arg_yyin, std::ostream& arg_yyout, ast_factory* fct) : yyFlexLexer{arg_yyin, arg_yyout}, fct(fct) {}
        scanner(std::istream* arg_yyin = nullptr, std::ostream* arg_yyout = nullptr, ast_factory* fct = nullptr) : yyFlexLexer{arg_yyin, arg_yyout}, fct(fct) {}
        virtual ~scanner() = default;
        virtual int yylex(parser::semantic_type* const lval, parser::location_type* location);
    private:
        ast_factory* fct = nullptr;
    };
}

#endif

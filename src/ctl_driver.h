#ifndef CTL_CTL_DRIVER_H
#define CTL_CTL_DRIVER_H
#include <string>
#include "ctl_syntax_tree.h"
#include "parser.hpp"
#define YY_DECL yy::parser::symbol_type yylex (ctl::driver* drv)
YY_DECL;

namespace ctl {
    struct driver {
        explicit driver() : trace_parsing(false), trace_scanning(false) {}
        virtual ~driver() = default;

        virtual int parse(const std::string &f) = 0;
        virtual auto get_symbol(const std::string &identifier) -> syntax_tree_t = 0;
        virtual void add_tree(const ctl::syntax_tree_t& tree) = 0;

        void scan_begin();
        void scan_end();

        std::string error;
        std::string file;
        bool trace_parsing;
        bool trace_scanning;
        yy::location location;
    };
}

#endif //CTL_CTL_DRIVER_H

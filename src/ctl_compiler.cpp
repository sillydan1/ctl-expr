#include "ctl_compiler.h"

namespace ctl {
    int compiler::parse(const std::string& f) {
        if (f.empty()) {
            error = "empty CTL string not allowed";
            return 1;
        }
        file = f;
        location.initialize(&file);
        scan_begin();
        ctl::parser parse(this);
        parse.set_debug_level(trace_parsing);
        try {
            int res = parse();
            scan_end();
            return res;
        } catch (std::exception &e) {
            error = e.what();
            return 1;
        }
    }
    auto compiler::get_symbol(const std::string& identifier) -> expr::syntax_tree_t {
        if(contains(identifier))
            return expr::syntax_tree_t{expr::identifier_t{identifier}};
        throw std::out_of_range(identifier + " not found");
    }
    void compiler::add_tree(const syntax_tree_t& tree) {
        ast = tree;
    }
    auto compiler::compile(const std::string &f) -> compiled_expr_t {
        ast = {};
        auto res = parse(f);
        if(res != 0)
            throw std::logic_error("invalid CTL expression: " + error);
        return ast;
    }
}

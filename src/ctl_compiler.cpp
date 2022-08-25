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
    auto compiler::get_symbol(const std::string& identifier) -> syntax_tree_t {
#ifndef NDEBUG
        if (!environment.contains(identifier))
            throw std::out_of_range(identifier + " not found");
#endif
        return syntax_tree_t{environment.find(identifier)};
    }
    void compiler::add_tree(const syntax_tree_t& tree) {
        ast = tree;
    }
}

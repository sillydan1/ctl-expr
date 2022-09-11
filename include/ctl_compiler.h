#ifndef CTL_CTL_COMPILER_H
#define CTL_CTL_COMPILER_H
#include "ctl_driver.h"

namespace ctl {
    class compiler : public driver {
    public:
        using compiled_expr_t = syntax_tree_t;
        compiler(std::initializer_list<symbol_table_ref_t> environments) : driver{environments}, ast{} {}
        int parse(const std::string &f) override;
        auto get_symbol(const std::string &identifier) -> expr::syntax_tree_t override;
        void add_tree(const syntax_tree_t& tree) override;
        auto compile(const std::string& f) -> compiled_expr_t;

        compiled_expr_t ast;
    };
}

#endif //CTL_CTL_COMPILER_H

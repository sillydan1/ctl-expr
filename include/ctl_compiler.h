#ifndef CTL_CTL_COMPILER_H
#define CTL_CTL_COMPILER_H
#include "ctl_driver.h"

namespace ctl {
    class compiler : public driver {
    public:
        using compiled_expr_t = syntax_tree_t;
        explicit compiler(const expr::symbol_table_t* env) : driver{}, ast{}, environments{env} {}
        compiler(const std::initializer_list<const expr::symbol_table_t*> env) : driver{}, ast{}, environments{env} {}
        int parse(const std::string &f) override;
        auto get_symbol(const std::string &identifier) -> expr::syntax_tree_t override;
        void add_tree(const syntax_tree_t& tree) override;
        auto compile(const std::string& f) -> compiled_expr_t;

        compiled_expr_t ast;
    protected:
        std::vector<const expr::symbol_table_t*> environments{};
    };
}

#endif //CTL_CTL_COMPILER_H

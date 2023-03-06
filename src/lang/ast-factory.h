#ifndef CTL_LANG_AST_FACTORY_H
#define CTL_LANG_AST_FACTORY_H
#include "../ctl_syntax_tree.h"
#include "symbol_table.h"

namespace ctl {
    class ast_factory {
        ast_factory() = default;
        virtual ~ast_factory() = default;
        virtual auto build_modal(const modal_op_t& op, const syntax_tree_t& tree) -> syntax_tree_t;
        virtual auto build_quantifier(const quantifier_t& op, const syntax_tree_t& child) -> syntax_tree_t;
        virtual auto build_quantifier(const quantifier_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t;
        virtual auto build_operator(const expr::operator_type_t& op, const syntax_tree_t& child) -> syntax_tree_t;
        virtual auto build_operator(const expr::operator_type_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t;
        virtual auto build_operator(const expr::operator_type_t& op, const std::vector<syntax_tree_t>& children) -> syntax_tree_t;
        virtual auto build_literal(const expr::symbol_value_t& value) -> syntax_tree_t;
        virtual auto build_identifier(const std::string& identifier) -> syntax_tree_t;
        virtual auto build_location(const std::string& location) -> syntax_tree_t;
        virtual auto build_root(const syntax_tree_t& child) -> syntax_tree_t;
    };
}

#endif


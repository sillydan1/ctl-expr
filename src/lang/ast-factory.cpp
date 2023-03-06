#include "ast-factory.h"
#include "symbol_table.h"

namespace ctl {
    auto ast_factory::build_modal(const modal_op_t& op, const syntax_tree_t& tree) -> syntax_tree_t {
    }

    auto ast_factory::build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child) -> syntax_tree_t {
    }

    auto ast_factory::build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t {
        return syntax_tree_t{};
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const syntax_tree_t& child) -> syntax_tree_t {
        return build_operator(op, {child});
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t {
        return build_operator(op, {child0, child1});
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const std::vector<syntax_tree_t>& children) -> syntax_tree_t {
        syntax_tree_t result{expr::operator_t{op}};
        for(auto& child : children)
            result.concat(child);
        return result;
    }
    
    auto ast_factory::build_literal(const expr::symbol_value_t& value) -> syntax_tree_t {
    }

    auto ast_factory::build_identifier(const std::string& identifier) -> syntax_tree_t {
    }

    auto ast_factory::build_location(const std::string& location) -> syntax_tree_t {
    }

    auto ast_factory::build_root(const syntax_tree_t& child) -> syntax_tree_t {
    }
}


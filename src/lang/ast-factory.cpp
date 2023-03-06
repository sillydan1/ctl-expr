#include "ast-factory.h"
#include "ctl_syntax_tree.h"
#include "symbol_table.h"

namespace ctl {
    auto ast_factory::build_modal(const modal_op_t& op, const syntax_tree_t& tree) -> syntax_tree_t {
        return syntax_tree_t{modal_t{op}}.concat(tree); 
    }

    auto ast_factory::build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child) -> syntax_tree_t {
        return build_quantifier(op, std::vector<syntax_tree_t>{child});
    }

    auto ast_factory::build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t {
        return build_quantifier(op, std::vector<syntax_tree_t>{child0, child1});
    }

    auto ast_factory::build_quantifier(const quantifier_op_t& op, const std::vector<syntax_tree_t>& children) -> syntax_tree_t {
        syntax_tree_t result{quantifier_t{op}};
        for(auto& child : children)
            result.concat(child);
        return result;
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const syntax_tree_t& child) -> syntax_tree_t {
        return build_operator(op, std::vector<syntax_tree_t>{child});
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t {
        return build_operator(op, std::vector<syntax_tree_t>{child0, child1});
    }

    auto ast_factory::build_operator(const expr::operator_type_t& op, const std::vector<syntax_tree_t>& children) -> syntax_tree_t {
        syntax_tree_t result{expr::operator_t{op}};
        for(auto& child : children)
            result.concat(child);
        return result;
    }
    
    auto ast_factory::build_literal(const expr::symbol_value_t& value) -> syntax_tree_t {
        return syntax_tree_t{value};
    }

    auto ast_factory::build_identifier(const std::string& identifier) -> syntax_tree_t {
        return syntax_tree_t{expr::identifier_t{identifier}};
    }

    auto ast_factory::build_location(const std::string& location) -> syntax_tree_t {
        return syntax_tree_t{location_t{location}};
    }

    auto ast_factory::build_root(const syntax_tree_t& child) -> syntax_tree_t {
        return syntax_tree_t{}.concat(child);
    }
}


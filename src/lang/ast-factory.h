/* MIT License
 *
 * Copyright (c) 2023 Asger Gitz-Johansen
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef CTL_LANG_AST_FACTORY_H
#define CTL_LANG_AST_FACTORY_H
#include "../ctl_syntax_tree.h"
#include "symbol_table.h"

namespace ctl {
    class ast_factory {
    public:
        ast_factory() = default;
        virtual ~ast_factory() = default;
        virtual auto build_modal(const modal_op_t& op, const syntax_tree_t& tree) -> syntax_tree_t;
        virtual auto build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child) -> syntax_tree_t;
        virtual auto build_quantifier(const quantifier_op_t& op, const syntax_tree_t& child0, const syntax_tree_t& child1) -> syntax_tree_t;
        virtual auto build_quantifier(const quantifier_op_t& op, const std::vector<syntax_tree_t>& children) -> syntax_tree_t;
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


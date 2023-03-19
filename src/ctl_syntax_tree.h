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
#ifndef CTL_SYNTAX_TREE_H
#define CTL_SYNTAX_TREE_H
#include <symbol_table.h>
#include <tree>
#include <utility>

namespace ctl {
    struct location_t {
        std::string location_name;
        explicit location_t(std::string name) : location_name{std::move(name)} {}
    };

    enum class modal_op_t {
        A,E
    };

    struct modal_t {
        modal_op_t operator_type;
        explicit modal_t(const modal_op_t& t) : operator_type{t} {}
    };

    enum class quantifier_op_t {
        X,F,G,U,W
    };

    struct quantifier_t {
        quantifier_op_t operator_type;
        explicit quantifier_t(const quantifier_op_t& t) : operator_type{t} {}
    };

    using underlying_syntax_node_t = std::variant<expr::syntax_tree_t, expr::operator_t, expr::root_t, location_t, modal_t, quantifier_t>;
    struct syntax_node_t : public underlying_syntax_node_t {
        syntax_node_t() : underlying_syntax_node_t{expr::root_t{}} {}
        template<typename T>
        syntax_node_t(const T &t) : underlying_syntax_node_t{t} {}
        syntax_node_t(const expr::identifier_t& t) : underlying_syntax_node_t(expr::syntax_tree_t{t}) {}
        syntax_node_t(const expr::operator_t& t) : underlying_syntax_node_t(expr::syntax_tree_t{t}) {}
        syntax_node_t(const expr::symbol_value_t& t) : underlying_syntax_node_t(expr::syntax_tree_t{t}) {}
        template<typename T>
        auto &operator=(const T &t) {
            this->underlying_syntax_node_t::operator=(t);
            return *this;
        }
    };
    using syntax_tree_t = ya::tree<syntax_node_t>;
    auto operator<<(std::ostream &o, const location_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const modal_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const quantifier_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const underlying_syntax_node_t &n) -> std::ostream &;
    auto operator<<(std::ostream &o, const syntax_tree_t &t) -> std::ostream &;
}

#endif


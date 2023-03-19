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
#include "ctl_syntax_tree.h"
#include <overload>
#include <algorithm>

namespace ctl {
    auto operator<<(std::ostream &o, const location_t &r) -> std::ostream & {
        return o << r.location_name << " L";
    }

    auto operator<<(std::ostream &o, const modal_t &r) -> std::ostream & {
        switch(r.operator_type) {
            case modal_op_t::A:
                return o << "A";
            case modal_op_t::E:
                return o << "E";
            default:
                return o << "unknown";
        }
    }

    auto operator<<(std::ostream &o, const quantifier_t &r) -> std::ostream & {
        switch (r.operator_type) {
            case quantifier_op_t::F:
                return o << "F";
            case quantifier_op_t::G:
                return o << "G";
            case quantifier_op_t::U:
                return o << "U";
            case quantifier_op_t::W:
                return o << "W";
            default:
                return o << "unknown";
        }
    }

    auto operator<<(std::ostream &o, const underlying_syntax_node_t &n) -> std::ostream & {
        std::visit(ya::overload(
                [&o](auto &&x) { o << x; }
        ), n);
        return o;
    }

    auto operator<<(std::ostream &o, const syntax_tree_t &tree) -> std::ostream & {
        if (tree.children().empty())
            return o << tree.node << " ";
        o << tree.node;
        o << "[";
        for (auto &c: tree.children())
            o << c;
        return o << "]";
    }
}

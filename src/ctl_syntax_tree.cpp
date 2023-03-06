#include "ctl_syntax_tree.h"
#include <overload>
#include <algorithm>

namespace ctl {
    auto operator<<(std::ostream &o, const location_t &r) -> std::ostream & {
        return o << r.location_name;
    }

    auto operator<<(std::ostream &o, const modal_op_t &r) -> std::ostream & {
        switch(r) {
            case modal_op_t::A:
                return o << "A";
            case modal_op_t::E:
                return o << "E";
            default:
                return o << "unknown";
        }
    }

    auto operator<<(std::ostream &o, const quantifier_op_t &r) -> std::ostream & {
        switch (r) {
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

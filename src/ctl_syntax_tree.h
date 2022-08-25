#ifndef CTL_SYNTAX_TREE_H
#define CTL_SYNTAX_TREE_H
#ifndef BINOP_CTOR
#define BINOP_CTOR(op,arg1,arg2) ctl::syntax_tree_t{expr::operator_t{expr::operator_type_t::op}}.concat(arg1).concat(arg2)
#define EXP_BINOP_CTOR(op,arg1,arg2) expr::syntax_tree_t{expr::operator_t{expr::operator_type_t::op}}.concat(arg1).concat(arg2)
#endif
#ifndef IDENT_CTOR
#define IDENT_CTOR(arg1) drv->get_symbol(arg1);
#define EXP_IDENT_CTOR(arg1) drv->get_symbol(arg1);
#endif
#ifndef MONOOP_CTOR
#define MONOOP_CTOR(op,arg1) ctl::syntax_tree_t{expr::operator_t{expr::operator_type_t::op}}.concat(arg1)
#define EXP_MONOOP_CTOR(op,arg1) expr::syntax_tree_t{expr::operator_t{expr::operator_type_t::op}}.concat(arg1)
#endif
#ifndef LIT_CTOR
#define LIT_CTOR(arg1) ctl::syntax_tree_t{arg1}
#define EXP_LIT_CTOR(arg1) expr::syntax_tree_t{arg1}
#endif
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

    enum class quantifier_t {
        X,F,G,U,W
    };

    using underlying_syntax_node_t = std::variant<expr::syntax_tree_t,
                                expr::operator_t, location_t, modal_op_t, quantifier_t>;
    struct syntax_node_t : public underlying_syntax_node_t {
        syntax_node_t() : underlying_syntax_node_t{expr::syntax_tree_t{expr::root_t{}}} {}
        template<typename T>
        syntax_node_t(const T &t) : underlying_syntax_node_t{t} {}
        syntax_node_t(const expr::syntax_tree_t& t) : underlying_syntax_node_t(t) {}
        template<typename T>
        auto &operator=(const T &t) {
            this->underlying_syntax_node_t::operator=(t);
            return *this;
        }
        auto& operator=(const expr::syntax_tree_t& t) {
            this->underlying_syntax_node_t::operator=(t);
            return *this;
        }
    };
    using syntax_tree_t = tree<syntax_node_t>;
    auto operator<<(std::ostream &o, const location_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const modal_op_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const quantifier_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const underlying_syntax_node_t &n) -> std::ostream &;
    auto operator<<(std::ostream &o, const syntax_tree_t &t) -> std::ostream &;
}

#endif //CTL_SYNTAX_TREE_H

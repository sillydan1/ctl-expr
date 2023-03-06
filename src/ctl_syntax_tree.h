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

    using underlying_syntax_node_t = std::variant<expr::syntax_tree_t, expr::operator_t, location_t, modal_t, quantifier_t>;
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
    using syntax_tree_t = ya::tree<syntax_node_t>;
    auto operator<<(std::ostream &o, const location_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const modal_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const quantifier_t &r) -> std::ostream &;
    auto operator<<(std::ostream &o, const underlying_syntax_node_t &n) -> std::ostream &;
    auto operator<<(std::ostream &o, const syntax_tree_t &t) -> std::ostream &;
}

#endif //CTL_SYNTAX_TREE_H

#ifndef CTL_CTL_DRIVER_H
#define CTL_CTL_DRIVER_H
#include <string>
#include "ctl_syntax_tree.h"
#include "ctl_parser.hpp"
#undef YY_DECL
#define YY_DECL ctl::parser::symbol_type ctllex (ctl::driver* drv)
YY_DECL;

namespace ctl {
    using symbol_table_ref_t = std::reference_wrapper<const expr::symbol_table_t>;
    using symbol_table_ref_collection_t = std::vector<std::reference_wrapper<const expr::symbol_table_t>>;
    struct driver {
        explicit driver(std::initializer_list<symbol_table_ref_t> environments) : trace_parsing(false), trace_scanning(false), environments{environments} {}
        virtual ~driver() = default;

        virtual int parse(const std::string &f) = 0;
        virtual auto get_symbol(const std::string &identifier) -> expr::syntax_tree_t = 0;
        virtual void add_tree(const ctl::syntax_tree_t& tree) = 0;

        void scan_begin();
        void scan_end();
        auto contains(const std::string& identifier) const -> bool {
            return find(identifier) != end;
        }
        auto find(const std::string& identifier) const -> expr::symbol_table_t::const_iterator {
            for(auto& env : environments) {
                auto env_it = env.get().find(identifier);
                if(env_it != env.get().end())
                    return env_it;
            }
            return end;
        }

        std::string error;
        std::string file;
        bool trace_parsing;
        bool trace_scanning;
        ctl::location location;
    protected:
        expr::symbol_table_t::const_iterator end{};
        symbol_table_ref_collection_t environments;
    };
}

#endif //CTL_CTL_DRIVER_H

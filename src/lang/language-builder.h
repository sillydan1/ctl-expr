#ifndef CTL_LANG_LANGUAGE_BUILDER_H
#define CTL_LANG_LANGUAGE_BUILDER_H
#include "../ctl_syntax_tree.h"

namespace ctl {
    class language_builder {
    public:
        language_builder() = default;
        virtual ~language_builder() = default;
        virtual auto add_query(const syntax_tree_t& tree) -> language_builder& = 0;
    };

    class multi_query_builder : public language_builder {
    public:
        struct result_t {
            std::vector<syntax_tree_t> queries;
        };
        auto add_query(const syntax_tree_t& tree) -> multi_query_builder& override;
        virtual auto build() -> result_t;
    private:
        result_t result{};
    };
}

#endif


#include "ast-factory.h"
#include "language-builder.h"

namespace ctl {
    auto multi_query_builder::add_query(const syntax_tree_t& tree) -> multi_query_builder& override {
        result.queries.push_back(tree);
        return *this;
    }

    auto multi_query_builder::build() -> result_t {
        return result;
    }
}


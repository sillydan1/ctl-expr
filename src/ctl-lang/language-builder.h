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


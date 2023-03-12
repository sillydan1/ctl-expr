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
#include <iostream>
#include <expr-lang/language-builder.h>
#include <expr-lang/ast-factory.h>
#include <expr-lang/expr-scanner.hpp>
#include <expr-lang/expr-parser.hpp>
#include "config.h"
#include "ctl-lang/ast-factory.h"
#include "ctl-scanner.hpp"
#include "ctl-parser.hpp"
#include "ctl_syntax_tree.h"
#include "language-builder.h"
#include <argvparse.h>
#include <sstream>
#include <stdexcept>

auto parse_query(const std::string& s) -> std::vector<ctl::syntax_tree_t> {
    std::istringstream iss{s};
    ctl::ast_factory factory{};
    ctl::multi_query_builder builder{};
    ctl::scanner scn{iss, std::cerr, &factory};
    ctl::parser_args pargs{&scn, &factory, &builder};
    ctl::parser p{pargs};
    if(p.parse() != 0)
        throw std::logic_error("unable to parse query expression");
    return builder.build().queries;
}

int main(int argc, char** argv) {
    std::vector<option_t> my_options = {
        {"expression", 'e',    argument_requirement::REQUIRE_ARG, "(required) provide the expression to process"},
    };
    auto cli_arguments = get_arguments(my_options, argc, argv);
    if(cli_arguments["help"] || !cli_arguments["expression"]) {
        std::cout << PROJECT_NAME << " v" << PROJECT_VER << "\n" << "OPTIONS:\n" << my_options;
        return 0;
    }
    auto result = parse_query(cli_arguments["expression"].as_string());
    int i = 0;
    for(auto& tree : result) 
        std::cout << "\t[" << i++ << "] ==> " << tree << "\n";
    return 0; 
}


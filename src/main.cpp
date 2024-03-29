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
#include "_deps/argvparse-src/src/arguments.h"
#include "config.h"
#include "ctl-lang/ast-factory.h"
#include "ctl-scanner.hpp"
#include "ctl-parser.hpp"
#include "ctl_syntax_tree.h"
#include "language-builder.h"
#include "symbol_table.h"
#include <generic-driver.h>
#include <argvparse.h>
#include <sstream>
#include <stdexcept>

auto parse_query(const std::string& s, unsigned int debug_level) -> std::vector<ctl::syntax_tree_t> {
    std::istringstream iss{s};
    ctl::ast_factory factory{};
    ctl::multi_query_builder builder{};
    ctl::scanner scn{iss, std::cerr, &factory};
    ctl::parser_args pargs{&scn, &factory, &builder};
    ctl::parser p{pargs};
    p.set_debug_level(debug_level);
    if(p.parse() != 0)
        throw std::logic_error("unable to parse query expression");
    return builder.build().queries;
}

int main(int argc, char** argv) {
    std::vector<option_t> my_options = {
        {"expression",  'e', argument_requirement::REQUIRE_ARG, "(required) provide the expression to process"},
        {"debug-level", 'd', argument_requirement::REQUIRE_ARG, "set parser debug level. Default is: 0"},
    };
    auto cli_arguments = get_arguments(my_options, argc, argv);
    if(cli_arguments["help"]) {
        std::cout << PROJECT_NAME << " v" << PROJECT_VER << "\n" << "OPTIONS:\n" << my_options;
        return 0;
    }
    std::string expression = cli_arguments["expression"].as_string_or_default("-");
    if(expression == "-") {
        std::rewind(stdin);
        std::cout << "provide CTL expressions (seperated by ';'). End with <<EOF>> (ctrl+d):\n<<\n";
        std::istreambuf_iterator<char> begin(std::cin), end;
        expression = std::string(begin, end);
        std::cout << "\n>>\n";
    }

    int i = 0;
    std::cout << "parsed AST(s):\n";
    for(auto& tree : parse_query(expression, cli_arguments["debug-level"].as_integer_or_default(0))) 
        std::cout << "\t[" << i++ << "] ==> " << tree << "\n";
    return 0; 
}


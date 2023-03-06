#include <iostream>
#include "ast-factory.h"
#include "config.h"
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


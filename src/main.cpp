#include <iostream>
#include "config.h"
#include <argvparse.h>

int main(int argc, char** argv) {
    std::vector<option_t> my_options = {
        {"expression", 'e',    argument_requirement::REQUIRE_ARG, "(required) provide the expression to process"},
    };
    auto cli_arguments = get_arguments(my_options, argc, argv);
    if(cli_arguments["help"] || !cli_arguments["expression"]) {
        std::cout << PROJECT_NAME << " v" << PROJECT_VER << "\n" << "OPTIONS:\n" << my_options;
        return 0;
    }
    std::cout << "still wip" << std::endl;
    return 0;
}

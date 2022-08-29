#include <iostream>
#include "config.h"
#include <argvparse.h>
#include <ctl_compiler.h>

int main(int argc, char** argv) {
    using namespace expr;
    symbol_table_t env{};
    std::vector<option_t> my_options = {
            {"expression", 'e',    argument_requirement::REQUIRE_ARG, "(required) provide the expression to process"},
            {"parser-trace", 'p',  argument_requirement::NO_ARG, "enable tracing for the parser"},
            {"scanner-trace", 's', argument_requirement::NO_ARG, "enable tracing for the scanner"},
    };
    auto cli_arguments = get_arguments(my_options, argc, argv);
    if(cli_arguments["help"] || !cli_arguments["expression"]) {
        std::cout
                << "=================== Welcome to the " << PROJECT_NAME << " v" << PROJECT_VER << " demo ==================\n"
                << "OPTIONS:\n"
                << my_options
                << "======================================================================\n";
        return 0;
    }

    try {
        ctl::compiler drv{&env};
        drv.trace_parsing = static_cast<bool>(cli_arguments["parser-trace"]);
        drv.trace_scanning = static_cast<bool>(cli_arguments["scanner-trace"]);
        std::cout << drv.compile(cli_arguments["expression"].as_string()) << std::endl;
        return 0;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}

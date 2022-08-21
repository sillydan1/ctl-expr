#include <iostream>
#include "ctl_syntax_tree.h"
#include "ctl_driver.h"
#include "config.h"
#include <argvparse.h>
#include <timer>

int main(int argc, char** argv) {
    using namespace expr;
    symbol_table_t env{};
    std::vector<option_t> my_options = {
            {"expression", 'e',    argument_requirement::REQUIRE_ARG, "(required) provide the expression to process"},
            // {"driver", 'd',        argument_requirement::REQUIRE_ARG, "(required) determine which driver to use [z3, interpreter, compiler]"},
            {"parser-trace", 'p',  argument_requirement::NO_ARG, "enable tracing for the parser"},
            {"scanner-trace", 's', argument_requirement::NO_ARG, "enable tracing for the scanner"},
    };
    auto cli_arguments = get_arguments(my_options, argc, argv);
    if(cli_arguments["help"] || !cli_arguments["expression"] || !cli_arguments["driver"]) {
        std::cout
                << "=================== Welcome to the " << PROJECT_NAME << " v" << PROJECT_VER << " demo ==================\n"
                << "OPTIONS:\n"
                << my_options
                << "======================================================================\n";
        return 0;
    }

    try {
        std::shared_ptr<ctl::driver> drv{};
        // TODO: Implement a basic example driver

        drv->trace_parsing = static_cast<bool>(cli_arguments["parser-trace"]);
        drv->trace_scanning = static_cast<bool>(cli_arguments["scanner-trace"]);

        ya::timer<int> t{};
        auto res = drv->parse(cli_arguments["expression"].as_string());
        if(res != 0) {
            std::cout << "error: " << drv->error << "\n";
            return res;
        }

        return 0;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}

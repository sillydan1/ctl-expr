# CTL expr
An extension of the C++ library [expr](https://github.com/sillydan1/expr), that recognises [Computation Tree Logic](https://en.wikipedia.org/wiki/Computation_tree_logic) 
and produces an AST

## Compile
This project uses CMake as the build tool.
Dependencies are handled automatically with [cpm](https://github.com/cpm-cmake/CPM.cmake), 
and the library is also built to be compatible with your
project if you use [cpm](https://github.com/cpm-cmake/CPM.cmake) as well.

```shell
mkdir bin && cd bin
cmake .. && make
```

## Usage
Below is a general usage example, this project also ships a [demo executable](src/main.cpp)
that prints the AST to stdout

```c++
...
#include <ctl_compiler.h>

// Add symbols to the context, so they can be referenced
expr::symbol_table_t symbols{};
symbols["a"] = 0;

// Construct the compiler
ctl::compiler compiler{symbols};

// Parse the CTL expression and check for syntax-success
int result_code = compiler.parse("E F a > 3");
if(result_code != 0)
    throw std::exception(compiler.error);

// Extract the abstract syntax tree for further analysis
auto ast = compiler.ast;
...
```

### AST Traversal

Using a library such as [yalibs/overload](https://github.com/yalibs/yaoverload) together with [std::visit](https://en.cppreference.com/w/cpp/utility/variant/visit), you can
traverse the ast recursively with type-dependent actions

```c++
#include <overload> // include yalibs/overload
#include <algorithm> // include std::visit

/* parse an expression (see above example) */
...
auto ast = compiler.ast;
// Do an action depending on the type of the node
std::visit(ya::overload(
    [&ast](const expr::symbol_reference_t &v)   { },
    [&ast](const expr::c_symbol_reference_t &v) { },
    [&ast](const expr::operator_t &v)           { },
    [&ast](const expr::root_t &v)               { },
    [&ast](const expr::symbol_value_t &v)       { },
    [&ast](const ctl::location_t &v)            { },
    [&ast](const ctl::modal_op_t &v)            { },
    [&ast](const ctl::quantifier_t &v)          { }
), ast.node);

for(auto& child : ast.children) {
    // Call a function on children of the tree
}
...
```

## CPM Dependencies
 - [sillydan1/expr @ v1.6.0](https://github.com/sillydan1/expr)
 - [sillydan1/argvparse @ v1.2.3](https://github.com/sillydan1/argvparse) (*only used for the demo executable*)
 - [yalibs/yatree @ v1.0.1](https://github.com/yalibs/yatree)
 - [yalibs/yaoverload @ v1.0.0](https://github.com/yalibs/yaoverload)
 - [yalibs/yahashcombine @ v1.0.0](https://github.com/yalibs/yahashcombine)

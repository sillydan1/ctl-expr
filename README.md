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
that prints the AST to stdout. For linking, simply link with the `libctl.so` library.

```c++
...
std::istringstream iss{"E F a > 3"};              // inputs must be wrapped in a stream
ctl::ast_factory factory{};                       // initialize an overridable ast factory
ctl::multi_query_builder builder{};               // initialize an overridable language builder
ctl::scanner scn{iss, std::cerr, &factory};       // initialize the scanner (print errors to cerr)
ctl::parser_args pargs{&scn, &factory, &builder}; // wrap arguments to the parser
ctl::parser p{pargs};                             // initialize the parser
if(p.parse() != 0)                                // parse the expression stream and handle error(s) if they occur
    throw std::logic_error("unable to parse query expression");
auto result = builder.build().queries;            // build and return the queries
for(int i = 0; i < result.size(); i++)            // print the resulting AST(s)
    std::cout << i << " ==> " << result[i] << "\n";
...
```

### AST Traversal

Using a library such as [yalibs/overload](https://github.com/yalibs/yaoverload) together with [std::visit](https://en.cppreference.com/w/cpp/utility/variant/visit), you can
traverse the ast recursively with type-dependent actions

```c++
#include <overload>  // include yalibs/overload
#include <algorithm> // include std::visit

/* parse an expression (see above example) */
...
auto ast = builder.build().queries;

// Do an action depending on the type of the node
std::visit(ya::overload(
    [&ast](const expr::syntax_tree_t &v)        { }, // See the expr library dependency
    [&ast](const expr::operator_t &v)           { },
    [&ast](const expr::root_t &v)               { },
    [&ast](const expr::symbol_value_t &v)       { },
    [&ast](const ctl::location_t &v)            { },
    [&ast](const ctl::modal_t &v)               { },
    [&ast](const ctl::quantifier_t &v)          { }
), static_cast<ctl::unerlying_syntax_node_t>(ast.node));

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


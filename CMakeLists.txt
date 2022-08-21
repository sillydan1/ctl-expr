cmake_minimum_required(VERSION 3.21)
project(ctl VERSION 1.0.0)
configure_file(src/config.h.in config.h)
include(cmake/CPM.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
CPMAddPackage("gh:sillydan1/expr#symbol-table-extensions")
CPMAddPackage("gh:yalibs/yatree@1.0.1")
CPMAddPackage("gh:yalibs/yaoverload@1.0.0")
CPMAddPackage("gh:yalibs/yatimer@1.0.0")
CPMAddPackage("gh:yalibs/yahashcombine@1.0.0")
CPMAddPackage("gh:sillydan1/argvparse@1.2.3")

include_directories(
        ${expr_SOURCE_DIR}/include
        ${yatree_SOURCE_DIR}/include
        ${yaoverload_SOURCE_DIR}/include
        ${yahashcombine_SOURCE_DIR}/include
        ${argvparse_SOURCE_DIR}/include
        ${yatimer_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
        include
        src
)

add_custom_command(OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/lex.l
        COMMAND m4
        ARGS -I ${PROJECT_SOURCE_DIR}/src/parser/lex -I ${expr_SOURCE_DIR}/src/parser/lex -P ${PROJECT_SOURCE_DIR}/src/parser/lex/scanner.l > ${CMAKE_CURRENT_BINARY_DIR}/lex.l
        VERBATIM)
add_custom_command(OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/yacc.y
        COMMAND m4
        ARGS -I ${PROJECT_SOURCE_DIR}/src/parser/yacc -I ${expr_SOURCE_DIR}/src/parser/yacc -P ${PROJECT_SOURCE_DIR}/src/parser/yacc/parser.y > ${CMAKE_CURRENT_BINARY_DIR}/yacc.y
        VERBATIM)

BISON_TARGET(ctl_parser ${CMAKE_CURRENT_BINARY_DIR}/yacc.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(ctl_lexer ${CMAKE_CURRENT_BINARY_DIR}/lex.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(ctl_lexer ctl_parser)

add_library(${PROJECT_NAME}
        ${BISON_ctl_parser_OUTPUTS}
        ${FLEX_ctl_lexer_OUTPUTS}
        src/ctl_syntax_tree.cpp)

add_executable(${PROJECT_NAME}_demo src/main.cpp)
target_link_libraries(${PROJECT_NAME}_demo ${PROJECT_NAME} expr)

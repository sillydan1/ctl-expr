cmake_minimum_required(VERSION 3.18)
project(ctl_lang VERSION 2.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
set(${PROJECT_NAME}_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE STRING "${PROJECT_NAME}_BUILD_DIR" FORCE) # CPM compatibility
BISON_TARGET(ctl_parser ctl.y ${CMAKE_CURRENT_BINARY_DIR}/ctl-parser.cpp)
FLEX_TARGET(ctl_lexer ctl.l ${CMAKE_CURRENT_BINARY_DIR}/ctl-scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(ctl_lexer ctl_parser)
add_library(${PROJECT_NAME} SHARED ${BISON_ctl_parser_OUTPUTS} ${FLEX_ctl_lexer_OUTPUTS} ast-factory.cpp language-builder.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_BINARY_DIR} 
    ${yaoverload_SOURCE_DIR}/include
    ${yatree_SOURCE_DIR}/include
    ${yatimer_SOURCE_DIR}/include
    ${yahashcombine_SOURCE_DIR}/include
    ${argvparse_SOURCE_DIR}/include
    .. .)
target_link_libraries(${PROJECT_NAME} ctl)


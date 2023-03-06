cmake_minimum_required(VERSION 3.18)
project(ctl VERSION 2.0.0)
configure_file(src/config.h.in config.h)
include(cmake/CPM.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
CPMAddPackage(NAME expr GIT_TAG feature/cpp-parsers GITHUB_REPOSITORY sillydan1/expr OPTIONS "ENABLE_Z3 OFF")
CPMAddPackage("gh:sillydan1/argvparse@1.2.3")
CPMAddPackage("gh:yalibs/yatree@1.2.1")
CPMAddPackage("gh:yalibs/yaoverload@1.0.0")
CPMAddPackage("gh:yalibs/yahashcombine@1.0.0")

add_library(${PROJECT_NAME} SHARED src/ctl_syntax_tree.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${expr_SOURCE_DIR}/include
        ${expr_SOURCE_DIR}/src
        ${expr_BUILD_DIR}
        ${yatree_SOURCE_DIR}/include
        ${yaoverload_SOURCE_DIR}/include
        ${yahashcombine_SOURCE_DIR}/include
        ${argvparse_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
        include
        src)

add_subdirectory(src/lang)
target_link_libraries(${PROJECT_NAME} ctl_lang)
add_executable(${PROJECT_NAME}_demo src/main.cpp)
target_link_libraries(${PROJECT_NAME}_demo ${PROJECT_NAME} argvparse)


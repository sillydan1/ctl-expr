# MIT License
# 
# Copyright (c) 2023 Asger Gitz-Johansen
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
cmake_minimum_required(VERSION 3.18)
project(ctl VERSION 2.0.0)
configure_file(src/config.h.in config.h)
include(cmake/CPM.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
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
        src/ctl-lang
        include
        src)

add_subdirectory(src/ctl-lang)
target_link_libraries(${PROJECT_NAME} ctl_lang expr_lang)
add_executable(${PROJECT_NAME}_demo src/main.cpp)
target_link_libraries(${PROJECT_NAME}_demo ${PROJECT_NAME} argvparse)


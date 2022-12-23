cmake_minimum_required(VERSION 3.21)
project(Trees)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trees binary_search_tree_tests.cpp)
add_executable(AVL avl_tree_tests.cpp)


add_executable(Makefile avl_tree_tests.cpp binary_search_tree_tests.cpp)

add_executable(b build_a_tree.cpp)

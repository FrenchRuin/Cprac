cmake_minimum_required(VERSION 3.23)
project(C C)

set(CMAKE_C_STANDARD 99)

#add_executable(C linkedLists/Polynomial.c)
add_executable(C stacks/paren_checker.c stacks/stackArray.c)

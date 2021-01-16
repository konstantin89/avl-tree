cmake_minimum_required(VERSION 3.1.2)

set(TESTS_BINARY_NAME tests)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
message(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ${AVL_TREE_LIB_INCLUDE_PATH})
conan_basic_setup()

add_executable(${TESTS_BINARY_NAME} main.cpp)

target_include_directories(
    ${TESTS_BINARY_NAME} PRIVATE 
    ${CONAN_INCLUDE_DIRS}
    ${AVL_TREE_LIB_INCLUDE_PATH})
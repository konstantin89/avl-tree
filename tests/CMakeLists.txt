cmake_minimum_required(VERSION 3.1.2)

set(CMAKE_BUILD_TYPE Debug)

set(TESTS_BINARY_NAME tests)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

set(TEST_SOURCES main.cpp data_set_tests.cpp basic_tests.cpp)

add_executable(${TESTS_BINARY_NAME} ${TEST_SOURCES})

target_include_directories(
    ${TESTS_BINARY_NAME} PRIVATE 
    ${CONAN_INCLUDE_DIRS}
    ${AVL_TREE_LIB_INCLUDE_PATH})
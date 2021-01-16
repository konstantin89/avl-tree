
cmake_minimum_required(VERSION 3.1.2)

set(LIBRARY_NAME "avt_tree_lib")

set(AVL_TREE_LIB_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

message("AVL tree library include path: " ${AVL_TREE_LIB_INCLUDE_PATH})

add_library(${LIBRARY_NAME} INTERFACE) 

target_include_directories(${LIBRARY_NAME} INTERFACE include/) 

add_subdirectory(tests)
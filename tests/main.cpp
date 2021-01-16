#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"

#include "avl_tree_lib/AvlTree.hpp"

using avl_tree_lib::AvlTree;

TEST_CASE( "Insert with empty root", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);

    REQUIRE(true == isValueInserted);
}

TEST_CASE( "Insert value twise", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(5);
    REQUIRE(false == isValueInserted);
}
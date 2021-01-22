#include "catch2/catch.hpp"

#include <vector>

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

TEST_CASE( "Insert basic set, no rotations", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(6);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(4);
    REQUIRE(true == isValueInserted);

}

TEST_CASE( "Insert basic set, right rotation", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(4);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(3);
    REQUIRE(true == isValueInserted);

}

TEST_CASE( "Find on empty tree", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto iterator = tree.Find(5);
    REQUIRE(iterator == tree.End());
}

TEST_CASE( "Insert and Find single value", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    auto iterator = tree.Find(5);
    REQUIRE(*iterator == 5);
}

TEST_CASE( "Insert and Find two values", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(3);
    REQUIRE(true == isValueInserted);

    auto iterator = tree.Find(5);
    REQUIRE(iterator != tree.End());
    REQUIRE(*iterator == 5);

    iterator = tree.Find(3);
    REQUIRE(iterator != tree.End());
    REQUIRE(*iterator == 3);
}
#include <catch2/catch_test_macros.hpp>
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

TEST_CASE( "Test right rotation", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(4);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(3);
    REQUIRE(true == isValueInserted);
}

TEST_CASE( "Test left rotation", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(0);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(1);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(2);
    REQUIRE(true == isValueInserted);

    auto iterator = tree.Find(0);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(1);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(2);
    REQUIRE(iterator != tree.End());
}

TEST_CASE( "Test left right rotation", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(3);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(4);
    REQUIRE(true == isValueInserted);

    auto iterator = tree.Find(5);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(3);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(4);
    REQUIRE(iterator != tree.End());
}

TEST_CASE( "Test right left rotation", "[AvlTree]" ) 
{
    AvlTree<int> tree;

    auto isValueInserted = tree.Insert(5);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(7);
    REQUIRE(true == isValueInserted);

    isValueInserted = tree.Insert(6);
    REQUIRE(true == isValueInserted);

    auto iterator = tree.Find(5);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(7);
    REQUIRE(iterator != tree.End());

    iterator = tree.Find(6);
    REQUIRE(iterator != tree.End());
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

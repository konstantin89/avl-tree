#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "avl_tree_lib/AvlTree.hpp"

using avl_tree_lib::AvlTree;

using TestSet = const std::vector<int>;

TestSet testSet1 = {0,1,2,3,4,5,6,7,8,9};
TestSet testSet2 = {5,4,6,1,7,9,8,7,10};
TestSet testSet3 = {6,3,6,1,2,3,45,1,67,89,78,67,66};
TestSet testSet4 = {23,12,54,67,34,23,12,34,45,56,56,56,12,67,45,27,78,105,234};


void testSet(TestSet setValues)
{
    AvlTree<int> tree;

    for(uint32_t i=0; i<setValues.size(); i++)
    {
        tree.Insert(setValues[i]);
    }

    for(auto value : setValues)
    {
        auto iterator = tree.Find(value);
        REQUIRE(iterator != tree.End());
        REQUIRE(*iterator == value);
    }
}

TEST_CASE( "Test data sets", "[AvlTree]" ) 
{
    INFO("Testing data set 1");
    testSet(testSet1);

    INFO("Testing data set 2");
    testSet(testSet2);

    INFO("Testing data set 3");
    testSet(testSet3);

    INFO("Testing data set 4");
    testSet(testSet4);
}
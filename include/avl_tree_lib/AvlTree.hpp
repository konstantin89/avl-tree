
#pragma once

#include "Node.hpp"

namespace avl_tree_lib
{

template <typename DataType>
class AvlTree
{

public:

    using NodeSharedPtrType = Node::NodeSharedPtrType;

public:

    AvlTree()
    {
        m_root = nullptr;
    }

    bool Insert(DataType data)
    {

    }

    bool Find(DataType data)
    {
        
    }

    bool Remove(DataType data)
    {
        
    }


private:

    NodeSharedPtrType m_root;

};

} // namespace avl_tree_lib


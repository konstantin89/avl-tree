#pragma once

namespace avl_tree_lib
{

template <typename DataType>
class Node
{
public:

using NodeSharedPtrType = std::shared_ptr<Node>;

public:

// TODO - default constructor

Node(NodeSharedPtrType left, odeSharedPtrType right, DataType data)
{
    m_left = left;
    m_right = right;
    m_data = data;
}

NodeSharedPtrType m_left;
NodeSharedPtrType m_right;
DataType m_data;

};


} //namespace avl_tree_lib



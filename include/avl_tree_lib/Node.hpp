#pragma once

namespace avl_tree_lib
{

template <typename DataType>
class Node
{
public:

using NodeSharedPtrType = std::shared_ptr<Node>;
using HeightType = uint32_t;
using BalanceType = int32_t;

private:

    static constexpr HeightType LEAFS_HEIGHT = 1;

public:

// TODO - default constructor

Node()
{
    m_parent = nullptr;
    m_left = nullptr;
    m_right = nullptr;
    m_data = {};
    m_height = LEAFS_HEIGHT;
}

Node(DataType data, NodeSharedPtrType parent)
{
    m_parent = parent;
    m_left = nullptr;
    m_right = nullptr;
    m_data = data;
    m_height = LEAFS_HEIGHT;
}

void UpdateHeight()
{
    HeightType leftChildHeight = 0;
    HeightType rightChildHeight = 0;

    if(nullptr != m_left)
    {
        leftChildHeight = m_left->m_height;
    }

    if(nullptr != m_right)
    {
        rightChildHeight = m_right->m_height;
    }

    m_height = std::max(leftChildHeight, rightChildHeight) + 1;
}

BalanceType GetBalance()
{
    HeightType leftChildHeight = 0;
    HeightType rightChildHeight = 0;

    if(nullptr != m_left)
    {
        leftChildHeight = m_left->m_height;
    }

    if(nullptr != m_right)
    {
        rightChildHeight = m_right->m_height;
    }

    return leftChildHeight - rightChildHeight;
}

NodeSharedPtrType m_parent;
NodeSharedPtrType m_left;
NodeSharedPtrType m_right;

DataType m_data;
HeightType m_height;

};


} //namespace avl_tree_lib



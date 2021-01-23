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


Node() : Node({}, nullptr, false)
{

}

Node(bool isEnd) : Node({}, nullptr, isEnd)
{

}

Node(DataType data, NodeSharedPtrType parent) :  
        Node(data, parent, false)
{

}

Node(DataType data, 
     NodeSharedPtrType parent, 
     bool isEnd)
{
    m_parent = parent;
    m_left = nullptr;
    m_right = nullptr;
    m_data = data;
    m_height = LEAFS_HEIGHT;
    m_isEnd = isEnd;
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

BalanceType GetBalance() const
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

bool IsEnd() const
{
    return m_isEnd;
}

NodeSharedPtrType m_parent;
NodeSharedPtrType m_left;
NodeSharedPtrType m_right;

DataType m_data;
HeightType m_height;

bool m_isEnd;

};


} //namespace avl_tree_lib



#pragma once

#include "avl_tree_lib/Node.hpp"

namespace avl_tree_lib
{

template <typename DataType>
class AvlTreeIterator
{

private:

    using NodeType = Node<DataType>;
    using NodeTypeReference = Node<DataType>;
    using NodeSharedPtrType = typename NodeType::NodeSharedPtrType;

public:

    AvlTreeIterator(NodeSharedPtrType node);

    ~AvlTreeIterator() = default;

    bool operator==(const AvlTreeIterator& other) const;

    bool operator!=(const AvlTreeIterator& other) const;

    AvlTreeIterator& operator++();

    DataType operator*() const;

protected:

    NodeSharedPtrType getInorderSuccessor(NodeSharedPtrType node);

    NodeSharedPtrType getMinOfSubtree(NodeSharedPtrType root);


private:

    NodeSharedPtrType m_current;
};



template <typename DataType>
AvlTreeIterator<DataType>::AvlTreeIterator(NodeSharedPtrType node)
{
    m_current = node;
}

template <typename DataType>
bool AvlTreeIterator<DataType>::operator==(const AvlTreeIterator& other) const
{ 
    if(m_current->IsEnd() && other.m_current->IsEnd())
    {
        return true;
    }

    else if(m_current->IsEnd())
    {
        return false;
    }
    
    else if(other.m_current->IsEnd())
    {
        return false;
    }
    else
    {
        return m_current->m_data == other.m_current->m_data;
    }
}

template <typename DataType>
bool AvlTreeIterator<DataType>::operator!=(const AvlTreeIterator& other) const
{ 
    return !(*this == other);
}

template <typename DataType>
AvlTreeIterator<DataType>& AvlTreeIterator<DataType>::operator++()
{
    m_current = getInorderSuccessor(m_current);
}

template <typename DataType>
DataType AvlTreeIterator<DataType>::operator*() const
{
    return m_current->m_data;
}

template <typename DataType>
typename AvlTreeIterator<DataType>::NodeSharedPtrType AvlTreeIterator<DataType>::getInorderSuccessor(NodeSharedPtrType node)
{
    
    if(nullptr != node->m_right)
    {
        return getMinOfSubtree(node->m_right);
    }

    NodeSharedPtrType current = node->m_parent;
    NodeSharedPtrType parent = current->m_parent;

    while (current != parent->m_left);
    {
        current = current->m_parent;
        parent = current->m_parent;
    } 
    
    return current;

}

template <typename DataType>
typename AvlTreeIterator<DataType>::NodeSharedPtrType AvlTreeIterator<DataType>::getMinOfSubtree(NodeSharedPtrType root)
{
    if(nullptr == root->m_left)
    {
        return root;
    }

    return getMinOfSubtree(root->left);
}



}
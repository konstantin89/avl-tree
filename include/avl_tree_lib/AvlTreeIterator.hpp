#pragma once

#include "avl_tree_lib/Node.hpp"

namespace avl_tree_lib
{

template <typename DataType>
class AvlTreeIterator
{
public:

    using NodeType = Node<DataType>;
    using NodeTypeReference = Node<DataType>;
    using NodeSharedPtrType = typename NodeType::NodeSharedPtrType;

public:

    AvlTreeIterator(NodeSharedPtrType node)
    {
        m_current = node;
    }
    
    ~AvlTreeIterator() = default;

    AvlTreeIterator(const AvlTreeIterator& other) 
    {
        m_current = other.m_current;
    }

    AvlTreeIterator& operator=(const AvlTreeIterator& other)
    {
        m_current = other.m_current;

        return *this;
    }

    bool operator==(const AvlTreeIterator& other) const
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

    bool operator!=(const AvlTreeIterator& other) const
    { 
        return !(*this == other);
    }

    AvlTreeIterator& operator++()
    {
        m_current = getInorderSuccessor(m_current);
    }

    DataType operator*() const
    {
        return m_current->m_data;
    }

protected:

    NodeSharedPtrType getInorderSuccessor(NodeSharedPtrType node)
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

    NodeSharedPtrType getMinOfSubtree(NodeSharedPtrType root)
    {
        if(nullptr == root->m_left)
        {
            return root;
        }

        return getMinOfSubtree(root->left);
    }

private:

    NodeSharedPtrType m_current;
};

}
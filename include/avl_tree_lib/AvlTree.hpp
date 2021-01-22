
#pragma once

#include "avl_tree_lib/Node.hpp"
#include "avl_tree_lib/AvlTreeIterator.hpp"

namespace avl_tree_lib
{

template <typename DataType>
class AvlTree
{

public:
    using NodeType = Node<DataType>;
    using NodeSharedPtrType = typename NodeType::NodeSharedPtrType;
    using AvlTreeIteratorType = AvlTreeIterator<DataType>;

public:

    AvlTree()
    {
        m_root = nullptr;
    }

    bool Insert(DataType newData)
    {       
        auto newNode = insertNode(newData);

        if(nullptr == newNode)
        {
            return false;
        }

        balanceNode(newNode->m_parent, newData);

        return true;

    }

    AvlTreeIteratorType Find(DataType data)
    {
        auto node = findNodeByData(data, m_root);

        if(nullptr == node)
        {
            return End();
        }

        return AvlTreeIteratorType(node);
    }

    AvlTreeIteratorType Begin()
    {
        if(nullptr == m_root)
        {
            return End();
        }

        auto minNode = getMinOfSubtree(m_root);

        return AvlTreeIteratorType(minNode);
    }

    AvlTreeIteratorType End()
    {
        auto endNode = std::make_shared<NodeType>(true);
        return AvlTreeIteratorType(endNode);
    }

    bool Remove(DataType data)
    {
        return true;
    }


protected:

    NodeSharedPtrType createNode(DataType data, NodeSharedPtrType parent)
    {
        return std::make_shared<NodeType>(data, parent);
    }

    NodeSharedPtrType insertNode(DataType newData)
    {
        NodeSharedPtrType current = m_root;
        NodeSharedPtrType parent = nullptr;

        while(current != nullptr)
        {
            parent = current;

            if(newData > current->m_data)
            {            
                current = current->m_right;
            }

            else if(newData < current->m_data)
            {
                current = current->m_left;
            }
            else
            {

                return nullptr;
            }
        }

        current = createNode(newData, parent);

        if(nullptr == m_root)
        {
            m_root = current;
        }

        else if(current->m_data > parent->m_data)
        {            
            parent->m_right = current;
        }

        else if(current->m_data < parent->m_data)
        {
            parent->m_left = current;
        }

        return current;
    }

    bool balanceNode(
        NodeSharedPtrType nodeToBalance,
        DataType newData)
    {
        if(nullptr == nodeToBalance)
        {
            return false;
        }

        auto balance = nodeToBalance->GetBalance();

        // Left rotatrion
        if ((balance > 1) && (newData < nodeToBalance->m_left->m_data))  
        {
            rotateRight(nodeToBalance);  
        }
            
        // Right rotatrion
        if ((balance < -1) && (newData > nodeToBalance->m_right->m_data))  
        {
            rotateLeft(nodeToBalance);  
        }
        
    
        // Left Right rotatrion  
        if ((balance > 1) && (newData > nodeToBalance->m_left->m_data))  
        {  
            nodeToBalance->m_left = rotateLeft(nodeToBalance->m_left);  
            rotateRight(nodeToBalance);  
        }  
    
        // Right Left rotatrion  
        if ((balance < -1) && (newData < nodeToBalance->m_right->m_data))  
        {  
            nodeToBalance->m_right = rotateRight(nodeToBalance->m_right);  
            rotateLeft(nodeToBalance);  
        }  

        return true;

    }

    NodeSharedPtrType rotateLeft(NodeSharedPtrType nodeToRotate)
    {
        auto z = nodeToRotate;
        auto y = z->m_right;
        auto T2 = y->m_right;

        y->m_left = z;
        z->m_left = T2;

        y->UpdateHeight();
        z->UpdateHeight();
        
        return y;

    }

    NodeSharedPtrType rotateRight(NodeSharedPtrType nodeToRotate)
    {
        auto z = nodeToRotate;
        auto y = z->m_left;
        auto T3 = y->m_right;

        y->m_right = z;
        z->m_left = T3;

        y->UpdateHeight();
        z->UpdateHeight();
        
        return y;
    }

    NodeSharedPtrType findNodeByData(
        DataType data, 
        NodeSharedPtrType root)
        {
            if(nullptr == root)
            {
                return nullptr;
            }

            if(data == root->m_data)
            {
                return root;
            }

            if(data > root->m_data)
            {
                return findNodeByData(data, root->m_right);
            }
            else
            {
                return findNodeByData(data, root->m_left);
            }
            
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

    NodeSharedPtrType m_root;
    
};

} // namespace avl_tree_lib


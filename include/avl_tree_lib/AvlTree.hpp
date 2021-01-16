
#pragma once

#include "avl_tree_lib/Node.hpp"

namespace avl_tree_lib
{

template <typename DataType>
class AvlTree
{

public:
    using NodeType = Node<DataType>;
    using NodeSharedPtrType = typename NodeType::NodeSharedPtrType;

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

    bool Find(DataType data)
    {
        return true;
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

private:

    NodeSharedPtrType m_root;

};

} // namespace avl_tree_lib



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
    using SizeType = uint64_t;

public:

    AvlTree()
    {
        m_root = nullptr;
        m_size = 0;
    }

    SizeType Size()
    {
        return m_size;
    }

    bool Insert(DataType newData)
    {       
        auto sizeBeforeInsertion = Size();

        m_root = insertNode(m_root, nullptr, newData);

        auto sizeAfterInsertion = Size();

        bool isValueInserted = sizeBeforeInsertion != sizeAfterInsertion;

        return isValueInserted;

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

    NodeSharedPtrType insertNode(
        NodeSharedPtrType node, 
        NodeSharedPtrType parent, 
        DataType newData)
    {
        if(nullptr == node)
        {
            m_size++;
            return createNode(newData, parent);
        }
        else if(node->m_data > newData)
        {
            node->m_left = insertNode(node->m_left, node, newData);
        }
        else if(node->m_data < newData)
        {
            node->m_right = insertNode(node->m_right, node, newData);
        }
        else
        {
            return node;
        }
        
        node->UpdateHeight();

        auto newRoot = balanceNode(node, newData);

        return newRoot;
    }

    NodeSharedPtrType balanceNode(NodeSharedPtrType nodeToBalance, DataType newData)
    {
        if(nullptr == nodeToBalance)
        {
            return nodeToBalance;
        }

        auto balance = nodeToBalance->GetBalance();

        // Left rotatrion
        if ((balance > 1) && (newData < nodeToBalance->m_left->m_data))  
        {
            return rotateRight(nodeToBalance);  
        }
            
        // Right rotatrion
        else if ((balance < -1) && (newData > nodeToBalance->m_right->m_data))  
        {
            return rotateLeft(nodeToBalance);  
        }
    
        // Left Right rotatrion  
        else if ((balance > 1) && (newData > nodeToBalance->m_left->m_data))  
        {  
            nodeToBalance->m_left = rotateLeft(nodeToBalance->m_left);  
            return rotateRight(nodeToBalance);  
        }  
    
        // Right Left rotatrion  
        else if ((balance < -1) && (newData < nodeToBalance->m_right->m_data))  
        {  
            nodeToBalance->m_right = rotateRight(nodeToBalance->m_right);  
            return rotateLeft(nodeToBalance);  
        }

        // Error case
        else
        {
             return nodeToBalance;
        }
        
    }

    NodeSharedPtrType rotateLeft(NodeSharedPtrType nodeToRotate)
    {
        auto z = nodeToRotate;        
        auto y = z->m_right;
        auto T2 = y->m_left;

        auto zOriginalParent = z->m_parent;

        y->m_left = z;
        y->m_parent = zOriginalParent;

        z->m_right = T2;
        z->m_parent = y;

        if(nullptr != T2)
        {
            T2->m_parent = z;
        }

        y->UpdateHeight();
        z->UpdateHeight();
        
        return y;

    }

    NodeSharedPtrType rotateRight(NodeSharedPtrType nodeToRotate)
    {
        auto z = nodeToRotate;
        auto zOriginalParent = z->m_parent;

        auto y = z->m_left;
        auto T3 = y->m_right;

        y->m_right = z;
        y->m_parent = zOriginalParent;

        z->m_left = T3;
        z->m_parent = y;

        if(nullptr != T3)
        {
            T3->m_parent = z;
        }
        

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
    SizeType m_size;
    
};

} // namespace avl_tree_lib


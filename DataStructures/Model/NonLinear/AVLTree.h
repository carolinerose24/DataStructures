//
//  AVLTree.h
//  DataStructures
//
//  Created by Jarman, Caroline on 4/30/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinarySearchTree.h"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    
    BinaryTreeNode<Type> * leftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation (BinaryTreeNode<Type> * parent);

    BinaryTreeNode<Type> * leftRightRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation (BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree (BinaryTreeNode<Type> * parent);
    
    //overloading these methods --> additional parameters to keep track of the parent
    BinaryTreeNode<Type> * insertNode (BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode (BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type> * parent);
  
public:
    AVLTree();
    void insert(Type itemToInsert);
    void remove(Type value);
    
    
    
};

/*
 Xcode's javadoc looks like this
 */

//overloaded methods --> remove and insert but also keep the balance-----------------------------------------------
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode (BinaryTreeNode<Type> * parent, Type inserted)
{
    if (parent == nullptr)
    {
        return parent;
    }
    if (inserted < parent->getNodeData())
    {
        parent->setLeftChildNode(removeNode(parent->getLeftChildNode(), inserted));
    }
    else if (inserted < parent->getNodeData())
    {
        parent->setRightChildNode(removeNode(parent->getRightChildNode(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if (parent->getLeftChildNode() == nullptr && parent0>getRightChildNode() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if (parent->getLeftChildNode() == nullptr)
        {
            *parent = *parent->getRightChildNode();
        }
        else if (parent->getRightChildNode() == nullptr)
        {
            *parent = *parent->getLeftChildNode();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRightChildNode());
            parent->setNodeData(leftMost->getNodeData());
            parent->setRightChildNode(removeNode(parent->getRightChildNode(), inserted));
        }
    }
    
    if (parent == nullptr)
    {
        return parent;
    }
    
    return balanceSubTree(parent);
}


template <class Type> //insert and balance tree
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode (BinaryTreeNode<Type> * parent, Type inserted)
{
    if (parent == nullptr) //if at the first thing, create new tree
    {
        parent = new BinaryTreeNode<Type>(inserted);
        this->setRoot(parent);
        return parent;
    }
    else if (inserted < parent->getNodeData()) //if there is a root-> set left node to parent
    {
        parent->setLeftChildNode(insertNode(parent->getLeftChildNode(), inserted));
        parent = balanceSubTree(parent);
    }
    else if (inserted > parent->getNodeData()) //set right node to parent
    {
        parent->setRightChildNode(insertNode(parent->getRightChildNode(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}


#endif /* AVLTree_h */

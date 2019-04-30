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

//-----------------------------------Constructor-------------------------------------------------
template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

//------------------------------------balance sub tree---------------------------------------------
/*
 to determine which side of the tree is bigger (left side - right side)
 if pos -> look to left side
 if neg -> look to right side
 */
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree (BinaryTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if (balanceFactor > 1)
    {
        if (heightDifference(parent->getLeftChildNode()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if (balanceFactor < - 1)
    {
        if (heightDifference(parent->getRightChildNode()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}

//-------------------------height difference-------------------------------------------
template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftChildNode());
    int rightHeight = this->calculateHeight(node->getRightChildNode());
    
    balance = leftHeight - rightHeight;
    return balance;
}


//-------------------------ROTATION METHODS---------------------------------------------------

//---------------left rotation---------------------------------------------
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;  //make pointer
    changedNode = parent->getLeftChildNode(); //set it to be the child
    
    parent->setLeftChildNode(changedNode->getRightChildNode()); //makes it the other side's child
    
    changedNode->setRightChildNode(parent); //set other child to the parent
    
    parent->setRootNode(changedNode); //tell parent who it's parent NOW is
    
    return changedNode; //return the new formation
}

//------------------right rotation----------------------------------------
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRightChildNode();
    
    parent->setRightChildNode(changedNode->getLeftChildNode());
    
    changedNode->setLeftChildNode(parent);
    parent->setRootNode(changedNode);
    
    return changedNode;
}

//--------------------------R/L rotation-----------------------------------
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRightChildNode();
    
    parent->setRightChildNode(leftRotation(changedNode)); //calls another methods
    
    return rightRotation(parent); //returns with ANOTHER call
}

//--------------------------L/R rotation------------------------------------
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChildNode();
    
    parent->setLeftChildNode(rightRotation(changedNode));
    
    return leftRotation(parent);
}


//------------overloaded methods --> remove and insert but also keep the balance------------------------------------

//-------------------------------------------REMOVE------------------------------------------------------
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


//--------------------------------------------INSERT----------------------------------------------------------
template <class Type> //insert and balance tree
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode (BinaryTreeNode<Type> * parent, Type inserted)
{
    if (parent == nullptr) //if at the first thing, create new tree
    {
        parent = new BinaryTreeNode<Type>(inserted);
        if (this->getRootNode() == nullptr)
        {
            this->setRootNode(parent);
        }
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
//----------------------------------------insert/remove small methods---------------------------------------------------
template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRootNode(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRootNode(), item);
}


#endif /* AVLTree_h */

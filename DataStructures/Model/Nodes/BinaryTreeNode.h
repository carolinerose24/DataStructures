//
//  BinaryTreeNode.h
//  DataStructures
//
//  Created by Jarman, Caroline on 4/12/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h

#include "Node.hpp"
#include <Assert.h>

template <class Type>
class BinaryTreeNode : public Node<Type>
{
private: //Data members here
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * leftChild;
    BinaryTreeNode<Type> * rightChild;
    
public:
    //constructors
    BinaryTreeNode<Type>();
    BinaryTreeNode<Type>(Type data);
    //getters
    BinaryTreeNode<Type> * getRootNode();
    BinaryTreeNode<Type> * getLeftChildNode();
    BinaryTreeNode<Type> * getRightChildNode();
    //setters
    void setRootNode (BinaryTreeNode<Type> * root);
    void setLeftChildNode (BinaryTreeNode<Type> * leftChild);
    void setRightChildNode (BinaryTreeNode<Type> * RightChild);
    
};




//----------------------------constructors----------------------
template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    root = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node <Type> (data)
{
    root = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}




//--------------------------getters-------------------------------
template <class Type>
Type BinaryTreeNode<Type> :: getRootNode()
{
    return this->root;
}

template <class Type>
Type BinaryTreeNode<Type> :: getLeftChildNode()
{
    return this->leftChild;
}

template <class Type>
Type BinaryTreeNode<Type> :: getRightChildNode()
{
    return this->rightChild;
}

//----------------------------setters-----------------------------
template <class Type>
void BinaryTreeNode<Type> :: setRootNode(BinaryTreeNode<Type> * root)
{
    root = newRoot;
}

template <class Type>
void BinaryTreeNode<Type> :: setLeftChildNode(BinaryTreeNode<Type> * leftChild)
{
    this->leftChild = leftChild;
}

template <class Type>
void BinaryTreeNode<Type> :: setRightChildNode(BinaryTreeNode<Type> * rightChild)
{
    this->rightChild = rightChild;
}





#endif /* BinaryTreeNode_h */

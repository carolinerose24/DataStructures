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

template <class Type>
class BinaryTreeNode : public Node<Type>
{
private:
    BinaryTreeNode<Type> root;
    BinaryTreeNode<Type> leftChild;
    BinaryTreeNode<Type> rightChild;
    
public:
    BinaryTreeNode<Type>();
    BinaryTreeNode<Type>(Type);
    
    Type getRoot();
    Type getLeftChild();
    Type getRightChild();
    
    void setRoot();
    void setLeftChild();
    void setRightChild();
    
};




//----------------------------constructors----------------------
template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode<Type>()
{}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode<Type>(Type)
{}




//--------------------------getters-------------------------------
template <class Type>
Type BinaryTreeNode<Type> :: getRoot()
{
    return root;
}

template <class Type>
Type BinaryTreeNode<Type> :: getLeftChild()
{
    return LeftChild;
}

template <class Type>
Type BinaryTreeNode<Type> :: getRightChild()
{
    return RightChild;
}

//----------------------------setters-----------------------------
template <class Type>
void BinaryTreeNode<Type> :: setRoot(BinaryTreeNode<Type>*)
{
    this->root = root;
}

template <class Type>
void BinaryTreeNode<Type> :: setLeftChild(BinaryTreeNode<Type>*)
{
    this->leftChild = leftChild;
}

template <class Type>
void BinaryTreeNode<Type> :: setRightChild(BinaryTreeNode<Type>*)
{
    this->rightChild = rightChild;
}





#endif /* BinaryTreeNode_h */

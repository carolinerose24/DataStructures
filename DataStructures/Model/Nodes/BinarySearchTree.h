//
//  BinarySearchTree.h
//  DataStructures
//
//  Created by Jarman, Caroline on 4/12/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
    //MARK:: Protected Methods
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    
    void destroyTree(BinaryTreeNode<Type> * node);
    
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    
    void removeNode (BinaryTreeNode<Type> * removeMe);
    
public:
    //MARK: Public Methods
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTreeNode<Type> * getRoot();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMaximum();
    Type findMinimum();
};



#endif /* BinarySearchTree_h */

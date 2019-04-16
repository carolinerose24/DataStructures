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

template <class Type> //definitions here, methods later
class BinarySearchTree : public Tree<Type>
{
    //MARK:: Protected Methods
protected:
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




//--------------informational method stubs-------------------

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    size += calculateSize(this->root);
    
    return size;
    
    
    //return -1;
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return calculateSize(current->getLeftChildNode()) + calculateSize(current->getRightChildNode()) + 1;
    }
    return 0;
}

// to compare strings in a tree, overloads --> does it by alphabetical a < b

//----------------------------get height / calculate height------------------------

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
    
    // return -1;
}


template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return max(calculateHeight(current->getLeftChildNode()), calculateHeight(current->getRightChildNode())) + 1;
    }
    return 0;
}





//-----------------is complete----------------------------------
template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
    //return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    
    if (index >= size)
    {
        return false;
    }
    
    return(isComplete(startNode->getLeftChildNode(), 2 * index + 1, size) && isComplete(startNode->getRightChildNode(), 2 * index + 2, size));
}


//---------------------------is balanced--------------------------------------
template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
    //return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if (current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftChildNode());
    rightHeight = calculateHeight(current->getRightChildNode());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftChildNode());
    bool rightBalanced = isBalanced(current->getRightChildNode());
    
    if (heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    return false;
    
}


//-------------------traversal stubs---------------------

//-------------------------in order---------------------------Left/Root/Right
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inorderTraversal(this->root);

}

//protected? idk what to do with this
//Recursive Traversal Implementation
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inOrderTraversal(currentNode->getLeftChildNode());
        cout << currentNode->getData() << endl;
        inOrderTraversal(currentNode->getRightChildNode());
    }
}


//-----------------------pre order--------------------------Root/Left/Right
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

//protected pre order traversal root, left, right
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getData() << endl;
        preOrderTraversal(currentNode->getLeftChildNode());
        preOrderTraversal(currentNode->getRightChildNode());
    }
}


//--------------------post order----------------------------- Left/Right/Root
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

//left, right, root
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postOrderTraversal(currentNode->getLeftChildNode());
        postOrderTraversal(currentNode->getRightChildNode());
        cout << currentNode->getData() << endl;
    }
}



//----------------------data operation stubs--------------
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if (current != nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if (itemToInsert < current->getData())
            {
                current = current->getLeftChildNode();
            }
            else if (itemToInsert > current->getData())
            {
                current = current->getRightChildNode();
            }
            else //remove cerr after verificaiton of understanding
            {
                cerr << "Item exists already - Exiting insert" << endl;
                delete insertMe;
                return; //returning nothing
            }
            
        }
        
        if (previous->getData() > itemToInsert)
        {
            previous->setLeftChildNode(insertMe);
        }
        else
        {
            previous->setRootNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type item)
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type item)
{
}

#endif /* BinarySearchTree_h */

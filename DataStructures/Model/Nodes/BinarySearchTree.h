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
    //MARK:: Public Methods
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


//MARK:: Tree Destructors
//-------------------------------tree destructors--------------------------------

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    destroyTree(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
    if (node != nullptr)
    {
        destroyTree(node->getLeftChildNode());
        destroyTree(node->getRightChildNode());
        delete node;
    }
}




//MARK:: info methods
//--------------informational method stubssss-------------------

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


//MARK:: Traversals
//-------------------traversal stubs (that are no longer stubs)---------------------

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


//MARK:: Data Operation Methods
//----------------------data operation stubs--------------
//------------------------------------------insert---------------------------------------
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
//--------------------------------------contains--------------------------------------------
template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else{
        while (current != nullptr)
        {
            if (itemToFind == current->getData())
            {
                return true;
            }
            else if (itemToFind < current->getData())
            {
                current = current->getLeftChildNode();
            }
            else
            {
                current = current->getRightChildNode();
            }
        }
        return false;
    }
    
}
//-----------------------------------------remove-----------------------------------------------
template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if (this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while (current != nullptr && !hasBeenFound)
        {
            if (current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if (getRidOfMe < current->getData())
                {
                    current = current->getLeftChildNode();
                }
                else
                {
                    current = current->getRightChildNode();
                }
            }
        }
        
        if (current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if (hasBeenFound)
        {
            if (current == this->root)
            {
                removeNode(this->root);
            }
            else if (getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftChildNode());
            }
            else
            {
                removeNode(previous->getRightChildNode());
            }
        }
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    
    previous = removeMe->getRootNode();
    
    //Node is a leaf -> has no kids
    
    if (removeMe->getRightChildNode() == nullptr && removeMe->getLeftChildNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if (previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftChildNode(removeMe);
        }
        else if (previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightChildNode(removeMe);
        }
        delete temp;
    }
    //Node only has a LEFT child
    else if(removeMe->getRightChildNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChildNode();
        
        if (previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeftChildNode(removeMe);
        }
        else if (previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRightChildNode(previous);
        }
        
        removeMe->setRootNode(previous);
        
        delete temp;
    }
    //Node only has a RIGHT child
    else if (removeMe->getLeftChildNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightChildNode();
        if (previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftChildNode(removeMe);
        }
        else if (previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightChildNode(removeMe);
        }
        
        removeMe->setRootNode(previous);
        delete temp;
    }
    //Node has BOTH children
    else
    {
        current = getRightMostChild(removeMe->getLeftChildNode());
        
        previous = current->getRootNode();
        removeMe->setData(current->getData());
        
        if (previous == nullptr)
        {
            removeMe->setLeftChildNode(current->getLeftChildNode());
        }
        else
        {
            previous->setRightChildNode(current->getLeftChildNode());
        }
        
        if (current->getLeftChildNode() != nullptr)
        {
            current->getLeftChildNode()->setRootNode(removeMe);
        }
        delete current;
    }
    //not sure if this last part goes here
    if (removeMe == nullptr || removeMe->getRootNode() == nullptr)
    {
        this->root = removeMe;
    }
    
    
}


//MARK:: Get left and Right Most
//-------------------get left most and right most----------------------------------------
template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode =currentNode->getLeftChildNode();
    }
    return previous;
}



template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode =currentNode->getRightChildNode();
    }
    return previous;
}

//MARK:: Min and Max
//-------------------------------find min and max-----------------------------
template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
}


//If adding words that have symbols like < or } or $ they are put at the FRONT -> BEFORE any regular words
//otherwise just sort by alphabetical order -> try to have the ROOT a mid alphabet letter or it will be VERY SKEWED
//still no duplicates so it would just disappear
//would capital letters count as a different word? if all the rest was the same --> would it count as a duplicate? or not?
//And would a capital letter word be Left or Right? (bigger or smaller) assuming it does NOT count as a duplicate

#endif /* BinarySearchTree_h */

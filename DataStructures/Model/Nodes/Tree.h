//
//  Tree.h
//  DataStructures
//
//  Created by Jarman, Caroline on 4/12/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinaryTreeNode.h"

template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //Informational Methods
    virtual int getSize() = 0;
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*Data Methods*
    virtual void insert(Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //Traversals
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;

};



#endif /* Tree_h */

//
//  BinaryTreeTester.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 4/12/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "BinaryTreeTester.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinaryTreeNode.h"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinarySearchTree.h"



template <class Type>
void BinaryTreeTester<Type> :: doTreeStuff()
{
    testTree.insert(22);
    testTree.insert(32);
    testTree.insert(76);
    testTree.insert(3433);
    testTree.insert(120);
    testTree.insert(6);
    testTree.insert(445);
    testTree.insert(104);
    //duplicates are thrown out --> not helpful to the tree
    //unbalanced trees are not as efficient as they could be (ex if 1 side has no kids)
    //balance from the bottom up --> rotate a parent to be a child, and then bring middle one up
    //but you HAVE to keep track of relationships and pointers
    
    testTree.inOrderTraversal();
    testTree.preOrderTraversal();
    testTree.postOrderTraversal();
    
    testTree.isBalanced();
    testTree.isComplete();
    testTree.getHeight();
    
}


//do I need anything for the private data members? or just the methods

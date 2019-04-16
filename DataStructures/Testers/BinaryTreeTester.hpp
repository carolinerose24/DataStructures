//
//  BinaryTreeTester.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 4/12/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include <iostream>
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinaryTreeNode.h"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Nodes/BinarySearchTree.h"

template <class Type>
class BinaryTreeTester
{
private:
    BinaryTreeNode<int> testNode; // no yellow line so it must be used somewhere?
    BinarySearchTree<int> testTree;
public:
    void doTreeStuff();
};

#endif /* BinaryTreeTester_hpp */

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


using namespace std;

template <class Type>
void BinaryTreeTester :: doTreeStuff()
{
    testTree.insert(22);
    testTree.insert(32);
    testTree.insert(76);
    testTree.insert(3433);
    testTree.insert(120);
    testTree.insert(6);
    testTree.insert(445);
    testTree.insert(104);
    
    testTree.inOrderTraversal();
}

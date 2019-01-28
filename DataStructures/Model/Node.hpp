//
//  Node.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 1/28/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Node_hpp //must be unique values
#define Node_hpp //at hpp right here? -> matches the file

#include <assert.h> //assert library put in base file (this one)

template <class Type> //tells that this IS a template class , type exists here (type of thung i'm storing)
class Node
{
private:
    Type data;
public:
    Node(Type data);
    Type getData();
    void setDAta(Type data);
};


#endif /* Node_h */

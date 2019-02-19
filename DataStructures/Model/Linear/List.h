//
//  List.h
//  DataStructures
//
//  Created by Jarman, Caroline on 2/7/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef List_h
#define List_h

#include "../Nodes/LinearNode.h"
#include <assert.h>

template <class Type>
class List
{
protected: //sub classes, not external classes can see it
    int size;
public:
    //Structure --> zero as a placeholder/abstract
    //have code/algorithms
    virtual void add(Type item) = 0; //virtual--> going to be overridden
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(int index) = 0;
    virtual Type getFromIndex(int index) = 0;
    //Helper -----Getters - not setters
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
    
};



#endif /* List_h */

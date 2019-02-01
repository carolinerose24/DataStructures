//
//  List.h
//  DataStructures
//
//  Created by Jarman, Caroline on 2/1/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef List_h
#define List_h
#include <assert.h>
#include "LinearNode.h"
//OR
#include "../../Nodes/LinearNode.hpp"

class List //: public List<Type>
{
protected:
    int size;
public:
    //Structure
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(int index) = 0;
    virtual Type getFromIndex(int index) = 0;
    //Helper
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
};


#endif /* List_h */

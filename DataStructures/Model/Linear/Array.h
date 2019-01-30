//
//  Array.h
//  DataStructures
//
//  Created by Jarman, Caroline on 1/30/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <assert.h>
#include <iostream>


template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
public:
    //Constructor
    Array<Type>(int size);
    
    //copy constructor
    Array<Type>(const Array<Type> & toCopy);
    
    //destructor
    ~Array<Type>();
    
    //operators
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //methods
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
    
};



template <class Type> //CONSTRUCTOR
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this -> size = size;
    
    internalArray = new Type[size];
}

template <class Type> //COPY constructor
Arra<Type> :: Array(const Array<Type> & to Copy)
{
    this->size = toCopy.getSize();
    
    //Build data structure
    internalArray = new Type[size];
    
    for (int index = 0; index < size; index++)
    {
        internalArray[index] = toCopy[index];
    }
}

template <class Type> //DESTRUCTOR
Array<Type> :: ~Array()
{
    delete [] internalArray;
}


#endif /* Array_h */

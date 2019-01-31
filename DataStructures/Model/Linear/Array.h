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

template <class Type> //Operators: my array -> shove into array (TO SET THE ENTIRE ARRAY)
Array<Type> & Array<Type> :: operator = (const Array<Type> & toAssign)
{ //IT MAKES THE = OPERATOR WORK FOR THING you MAKE
    if (&toAssign != this) //is it what I am talking about? CHECKS ADDRESS (if they are the same)
    {
        if (size != toAssign.getSize())
        {
            delete [] internalArray; //if no, delete old and fill it with mine
            size = toAssign.getSize();
            internalArray = new Type [size];
        }
        
        for (int index = 0; index < size; index++)
        {
            internalArray[index] = toAssign[index];
        }
    }
    return *this;
}

template <class Type> //another operator?
Type & Array<Type> :: operator [] (int index)
{
    assert (index >= 0 && index < size);
    return internalArray[index];
}

template <class Type>
Type Array<Type> :: operator [] (int index) const
{
    assert (index >= 0 && index < size);
    return internalArray[index];
}

template <class Type> //methods: ---------
int Array<Type> :: getSize() const
{
    return size;
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert (index >= 0 && index < size);
    
    Type value = internalArray[index];
    
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int pos, Type item)
{
    assert(pos >= 0 && pos < size);
    internalArray[pos] = item;
}

#endif /* Array_h */

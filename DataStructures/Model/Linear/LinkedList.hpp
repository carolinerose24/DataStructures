//
//  LinkedList.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/1/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.h"
#include <stdio.h>


using namespace std; //~ is for the destructor

class LinkedList : public List<Type>
{
protected:
    LinearNode<Type> * front;
    LinearNode<Type> * end;
public:
    //Constructors
    LinkedList();
    //Destructor
    virtual ~ LinkedList(); //Virtual so it can be overridden
    //Helper methods
    int getSize() const;
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
    //Structure methods
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type getFromIndex(int index);
    Type remove(int index);
    //Type setAtIndex(int index, Type item);
    bool contains(Type item);

};

template <class Type> //can put anything inside of it
LinkedList<Type> :: LinkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}

template <class Type>
LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while (fornt != nullptr)
    {
        front = destroyStructure -> getNextNode(); //loop through node and delete memory allocations
        delete destroyStructure;
        destroyStructure = front;
    }
}

template <class Type>
void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if(this->size == 0) //add method
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData); //point the last node to the new data
    }
    
    this->end = newData;
    this->size += 1;
}

template <class Type>
void LinkedList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= this->size)
    if (index == this->size)
    {
        add(item);
    }
    else
    {
        LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
        if (index == 0)
        {
            toBeAdded->setNextNode(front);
            front = toBeAdded;
        }
        else
        {
            LinearNode<Type> * previous = nullptr;
            LinearNode<Type> * current = front;
            
            for(int position = 0; position < index; position++)
            {
                previous = current;
                current = current -> getNextNode();
            }
            previous->setNextNode(toBeAdded);
            toBeAdded->setNextNode(current);
        }
        this->size++;
    }
    
}

template <class Type>
Type LinkedList<Type> :: getFromIndex(int index)
{
    assert(index >= = && index < this->size);
    Type data:
    LinearNode<Type> * current = front; //start at beginning
    
    for (int position = 0; position < index; position++)
    {
        current = current->getNextNode(); //current node calling method get next node
    }
    
    data = current -> getData();
    return data;
}

template <class Type>
Type LinkedList<Type> :: remove (int index)
{
    assert (index>= 0 && index < this-> size);
    
    LinearNode<Type> * current = front;
    LinearNode<Type> * toBeRemoved = nullptr;
    LinearNode<Type> * previous = nullptr;
    
    Type removedData;
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = this->front->getNextNode();
    }
    else
    {
        for (int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextNode();
        }
        
        toBeRemoved = current;
        if(index == this->size - 1) //to prevent out of bounds
        {
            previous ->setNextNode(nullptr);
            end = previous;
        }
        else
        {
            current = toBeRemoved -> getNextNode();
            previous->setNextNode(current);
        }
    }
    this->size -= 1;
    
    removedData = toBeRemoved->getData();
    delete toBeRemoved; //find data you want gone, then delete it
    return removedData;
}

template <class Type>
LinearNode<Type> * LinkedList<Type> :: getEnd()
{
    return this->end;
}

template <class Type>
LinearNode<Type> * LinkedList<Type> :: getFront()
{
    return this->front;
}

template <class Type>
int LinkedList<Type>  :: getSize() const
{
    return this->size;
}


template <class Type>
bool LinkedList<Type> :: contains(Type thingToFind)
{
    bool exists = false;
    
    LinearNode<Type> * searchPointer = front;
    for (int index = 0; index < this->size; index++)
    {
        if (searchPointer->getData() == thingToFind) ==no .equals method
        {
            exists = true;
            //or put return true here which leaves the method
        }
        searchPointer = searchPointer->getNextNode();
    }
    
    return exists;
}

//template <class Type>
//class LinkedList : public List<Type>


#endif /* LinkedList_hpp */

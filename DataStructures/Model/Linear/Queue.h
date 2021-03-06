//
//  Queue.h
//  DataStructures
//
//  Created by Jarman, Caroline on 2/11/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.hpp"

#include<iostream>
using namespace std;

template <class Type>
class Queue : public LinkedList<Type>
{
public:
    Queue();
    ~Queue();
    
    //Queue methods
    void enqueue(Type data);
    Type dequeue();
    Type peek();
    void clear();
    
    //Overridden LinkedList methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
    
};

template <class Type>
Queue<Type> :: Queue() : LinkedList<Type>()
{
    //empty because it is handled by the parent class constructor
}

template <class Type>
Queue<Type> :: ~Queue() //destructor
{
    for (LinearNode<Type> * removed = this->front; removed!= nullptr; removed = this->front)
    {
        this->front = removed ->getNextNode();
        delete removed;
    }
}

template <class Type>
void Queue<Type> :: enqueue(Type item)
{
    LinearNode<Type> * added = new LinearNode<Type>(item);
    
    if(this->size == 0)
    {
        this->front = added;
    }
    else
    {
        this->end->setNextNode(added);
    }
    this->end = added;
    this->size++;
}

template <class Type>
void Queue<Type> :: addAtIndex(int index, Type item)
{
    assert(index == this->size);
    enqueue(item);
}

template <class Type>
void Queue<Type> :: add(Type item)
{
    enqueue(item);//adds a value
}

template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->size > 0);
    
    Type return1 = this->front->getData();
    
    LinearNode<Type> * removed = this->front;
    this->front = removed->getNextNode();
    
    delete removed;
    
    this->size = this->size - 1;
    
    return return1;
}

template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0);
    return dequeue(); //removes a value
}

template <class Type>
void Queue<Type> :: clear()
{
    while (this->front != nullptr)
    {
        cout << dequeue() << endl;
    }
}

template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->size > 0);
    return this->getFront()->getData(); //get data from front and return it
}

template <class Type>
Type Queue<Type> :: getFromIndex(int index)
{
    assert(index == 0);
    return peek();
}


#endif /* Queue_h */

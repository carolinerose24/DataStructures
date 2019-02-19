//
//  Stack.h
//  DataStructures
//
//  Created by Jarman, Caroline on 2/11/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "LinkedList.hpp"

template <class Type>
class Stack : public LinkedList<Type>
{
public:
    Stack();
    ~Stack();
    
    //Stack specific methods
    void push(Type data); //put value at top of stack
    Type pop(); //returns and removes ^^ value
    Type peek(); //retrieves top value w/o removing it
    
    //overridden linkedlist methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
};

template <class Type>
Stack<Type> :: Stack() : LinkedList<Type>()
{
    //empty constructor
}

template <class Type>
Stack<Type> :: ~Stack() //destructor-> called by the compiler at the end
{
    while(this->size > 0)
    {
        pop();
    }
}

template <class Type>
void Stack<Type> :: push(Type data)
{

LinearNode<Type> * add = new LinearNode<Type>(data);

if(this->size == 0)
{
    this->end = add;
}
else
{
    add->setNextNode(this->front);
}
this->front = add;
this->size++;
}

template <class Type>
void Stack<Type> :: add(Type data)
{
    push(data);
}

template <class Type>
void Stack<Type> :: addAtIndex(int index, Type data)
{
    assert(index == 0);
    push(data);
}

template <class Type>
Type Stack<Type> :: pop()
{
    assert (this->size>0);
    Type removed = this->front->getData();
    
    LinearNode<Type> * removedNode = this-> getFront();
    this->front = removedNode->getNextNode();
    delete removedNode;
    
    this->size--;
    return removed;
}

template <class Type>
Type Stack<Type> :: remove(int index) //have to have, but just calls pop
{
    assert(index == 0);
    return pop();
}

template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->size > 0);
    return this->getFront()->getData();
}

template <class Type>
Type Stack<Type> :: getFromIndex(int index)
{
    assert(index==0);
    return peek();
}


//Stack notes
//Add at zero, zero points to next
//Have to destroy the stack to get to the bottom of it

//Stack<Lego> myStack; //no parens
//myStack push(lego1);


//remove at zero
//add at end

//HAVE TO HAVE ADD AT INDEX/OTHER LIST METHODS

#endif /* Stack_h */

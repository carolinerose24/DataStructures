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
    Stack()
    ~Stack();
    
    //Stack specific methods
    void push(Type data); //put value at top of stack
    Type pop(); //returns and removes ^^ value
    Type peak(); //retrieves top value w/o removing it
    
    //overridden linkedlist methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
};

template <class Type>
Stack<Type> :: Stack : LinkedList<Type>()
{
    //empty constructor
}

template <class Type>
Stack<Type> :: ~Stack()
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
    add->setNextNode(this->front)
}
this->front = add;
this->size++;
}

#endif /* Stack_h */

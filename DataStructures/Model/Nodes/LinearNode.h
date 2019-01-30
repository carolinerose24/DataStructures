//
//  LinearNode.h
//  DataStructures
//
//  Created by Jarman, Caroline on 1/30/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef LinearNode_h
#define LinearNode_h
#include "Node.hpp"


template <class Type>
class LinearNode : public Node<Type>
{
private:
    LinearNode<Type> * next; //* is making a pointer (operator)
public: //points to another Linear Node next to it
    LinearNode();
    LinearNode(Type data);
    LinearNode(Type data, LinearNode<Type> * next)
    LinearNode<Type> * getNext();
    void setNext(LinearNode<Type> * next)
};

//implementation of templates
//----------------------------------------constructors---------------------------------------------------------------
template <class Type>
LinearNode<Type> :: LinearNode() : Node() // : mean inheritance
{}

template <class Type> //THIS IS THE CONSTRUCTOR
LinearNode<Type> :: LinearNode (Type data) : Node<Type>(data) //: calls parent class, sends parameter to it (data) and returns data member
{                // of type data                 ^^constructor (Java ~= super(data))
    this->next = nullptr;
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data, LinearNode<Type> * next) : Node<Type>(data)
{
    this->next = next;
}
//----------------------------------------------methods--------------------------------------------------------------------
template <class Type>
LinearNode<Type> * LinearNode<Type> :: getNext()
{
    return this->next;
}

template <class Type>
void LinearNode<Type> :: setNext(LinearNode<Type> * next) //points to next node?
{
    this->next = next;
}


//---------------------------Array methods
//*Constructor
//Fixed size 0...max
//Memory Allocation --> based on parameter, and connect the nodes
//*getFromIndex (int):Type
//*setAtIndex(int, Type)
//*getSize(): int()


// a node is a bucket that can hold things and hook it to other things
//put things inside (types)
//for structural organization
//colon means 'of type' in uml



#endif /* LinearNode_h */    //Linear node is like Node but has NEXT

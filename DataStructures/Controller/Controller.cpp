//
//  Controller.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 1/28/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "Controller.hpp" //linker error--> check #include's


//MARK:- stuff

void Controller :: start()
{
    cout << "This is the data structures app" << endl;
    testLinear();
    
    //put breakpoint here? when fixing errors/debugging,
    //step over: 1 line then waits
    //step into: go in and wait (follows path to where it leads)
    //step out: jumps all the way out if you are done with a path
}

void Controller:: usingNodes()
{
    Node<int> mine(5);
    Node<string> wordHolder("words can be stored too");
    cout << mine.getData() << endl;
    cout << wordHolder.getData() << endl;
    wordHolder.setData("replaced text");
    cout << wordHolder.getData() << endl;
    
    cout << "I keep it poppin'" << endl;
    
}

void Controller :: testLinear()
{ //these are put on the stack
    linearTester lookieHere;
    lookieHere.testVsSTL();
    
} //destructed after this ends (popped off the stack)





void Controller :: testFiles()
{
//    vector<int> Vectorrr;
//    
////    for (int i = 0; i < Vectorrr.length; i ++)
////    {
////
////    }
//    
//    for (auto i = Vectorrr.begin(); i != Vectorrr.end(); ++i)
//    {
//        cout << *i << endl;
//    }
//    
//    cout << index << ": contents are: " << Vectorrr[index] << endl;
//    
}

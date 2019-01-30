//
//  Controller.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 1/28/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "Controller.hpp" //linker error--> check #include's

void Controller :: start()
{
    cout << "This is the data structures app" << endl;
    usingNodes();
}

void Controller:: usingNodes()
{
    Node<int> mine(5);
    Node<string> wordHolder("words can be stored too");
    cout << mine.getData() << endl;
    cout << wordHolder.getData() << endl;
    wordHolder.setData("replaced text");
    cout << wordHolder.getData() << endl;
    
}

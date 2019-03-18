//
//  Controller.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 1/28/19.
//  Copyright © 2019 ctec. All rights reserved.
//

//Templates only go in HEADER FILES
    //to be compiled at run time
#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include "../Model/Nodes/Node.hpp"
#include "../Model/Nodes/LinearNode.h"
#include "FileController.hpp"
#include "../Testers/linearTester.hpp"

using namespace std;

class Controller
{
private:
    void usingNodes();
    void testFiles();
    void testLinear();
    void testGraphStuff();
public:
    void start();

};




#endif /* Controller_hpp */

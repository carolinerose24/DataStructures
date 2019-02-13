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
#include "FileController.hpp"


using namespace std;

class Controller
{
private:
    void usingNodes();
    void testFiles();
public:
    void start();

};




#endif /* Controller_hpp */

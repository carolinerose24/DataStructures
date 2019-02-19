//
//  linearTester.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/13/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef linearTester_hpp
#define linearTester_hpp

#include "../Controller/Tools/Timer.hpp"
#include "../Controller/Tools/FileController.hpp"

#include "../Model/Linear/LinkedList.hpp"
#include "../Model/Linear/Stack.h"
#include "../Model/Linear/Queue.h"
#include "../Model/Linear/Array.h"

//#include ""

#include <iostream>
using namespace std;

class linearTester
{
public:
    void testVsSTL();
};


#endif /* linearTester_hpp */

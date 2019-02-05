//
//  FileController.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/5/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <stdio.h>
//#include "../Resources/Music.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string filename);
};


#endif /* FileController_hpp */

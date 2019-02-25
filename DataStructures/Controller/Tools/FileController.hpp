//
//  FileController.hpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/5/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp
//error-> reveal in log to further examine what your error is

//#include "Music.hpp"
#include "CrimeData.hpp"

#include "Array.h"
#include "LinkedList.hpp"
#include "/Users/cjar7174/Downloads/Music.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Linear/Queue.h"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Linear/Stack.h"
//#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Linear/CircularList.h"


//#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std; //standard library access

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string filename);
    
    static LinkedList<CrimeData> readDataToList(string filename);
    static LinkedList<Music> musicDataToList (string filename);
    static Array<Music> musicDataToArray(string filename);
    
    static Queue<Music> musicDataToQueue(string filename);
    static Stack<Music> musicDataToStack(string filename);
    
//    static CircularList<CrimeData> crimeDataToCircularList(string filename);
    
};


#endif /* FileController_hpp */

//
//  linearTester.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/13/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "linearTester.hpp"

void linearTester :: testVsSTL()

{
    Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
    //don't use new unless making a pointer
    
    crimeTimerSTL.startTimer(); //vector class is highly optimized, faster
    vector<CrimeData> crimes = FileController :: readCrimeDataToVector("/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Resources/crime.csv");
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer(); //hand typed code, slower
    LinkedList<CrimeData> moreCrimes = FileController :: readDataToList("/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Resources/crime.csv");
    
    crimeTimerSTL.displayInformation();
    crimeTimerOOP.displayInformation();
    
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
}

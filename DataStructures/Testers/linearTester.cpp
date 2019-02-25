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
    
        cout << "This is the STL: " << endl;
    crimeTimerSTL.displayInformation();
        cout << "This is the OOP node: " << endl;
    crimeTimerOOP.displayInformation();
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;


    musicSTL.startTimer();
    vector<Music> tunez = FileController :: musicDataToVector("/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Resources/music.csv");
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    LinkedList<Music> musicList = FileController :: musicDataToList("/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Resources/music.csv");
    musicOOP.stopTimer();
    
    cout << "This is the STL: " << endl;
    musicSTL.displayInformation();
    cout << "This is the OOP node: " << endl;
    musicOOP.displayInformation();
    
    cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;

    crimeTimerOOP.resetTimer();
    crimeTimerSTL.resetTimer();
    musicOOP.resetTimer();
    musicSTL.resetTimer();
    
}

void linearTester:: testVStack()
{
    
}

void linearTester:: testVsQueue()
{
    
}

void linearTester:: testVsDouble()
{
    
}

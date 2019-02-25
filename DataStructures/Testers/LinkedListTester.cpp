//
//  LinkedListTester.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/25/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "LinkedListTester.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Model/Linear/LinkedList.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Controller/Tools/Timer.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Resources/CrimeData.hpp"
#include "/Users/cjar7174/Documents/C++ Folder/DataStructures/DataStructures/Controller/Tools/FileController.hpp"

using namespace std;

void LinkedListTester :: testListBasics()
{
    LinkedList<int> numbers;
    numbers.add(9);
    cout << numbers.getFront() -> getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd() -> getData() << " Is at the end of the list and should be 9" << endl;
    
    numbers.add(0);
    cout << numbers.getFront() -> getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd() -> getData() << " Is at the end of the list and should be 0" << endl;
    
    numbers.addAtIndex(1, 2);
    numbers.add(324);
    
    cout << numbers.getFront() -> getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd() -> getData() << " Is at the end of the list and should be 324" << endl;
    
    cout <<"This loop should print four lines" << endl;
    for (int index = 0; index < numbers.getSize(); index++)
    {
        cout << numbers.getFromIndex(index);
    }
    
    numbers.remove(0);
    numbers.add(32567);
    numbers.addAtIndex(0, 2312);
    
    cout << numbers.getFront() -> getData() << " Is at the front of the list and should be 2312" << endl;
    cout << numbers.getEnd() -> getData() << " Is at the end of the list and should be 32567" << endl;
    
}

void LinkedListTester:: testListWithData()
{
    Timer listTimer;
    
    listTimer.startTimer();
    LinkedList<CrimeData> crimes = FileController :: readDataToList("/Users/cjar7174/Downloads/crime (1).csv");
    listTimer.stopTimer();
    cout << "This is how long it took to read the structure into our custom data structure" << endl;
    listTimer.displayInformation();
    
    listTimer.resetTimer();
    cout << "This is how long it takes to access a random data value" << endl;
    listTimer.startTimer();
    int randomLocation = (rand(0 * rand()) % crimes.getSize());
    cout << "The random index is " << randomLocation << endl;
    double totalViolenceRate = crimes.getFromIndex(randomLocation).getAllViolentRates();
    listTimer.stopTimer();
    cout << "The random crime stat is: " << totalViolenceRate << ", and here is the time" << endl;
    listTimer.displayInformation();
    
    
}

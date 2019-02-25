//
//  FileController.cpp
//  DataStructures
//
//  Created by Jarman, Caroline on 2/5/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#include "FileController.hpp"


#include "../../Model/Linear/LinkedList.hpp"
#include "../../Model/Linear/Array.h"

#include <sstream>


vector<CrimeData> FileController :: readCrimeDataToVector(string filename)
{
    std :: vector<CrimeData> crimeVector;
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(filename); //input file stream -->not owned by us, cannot be debugged
    
    //if this file exists at that path
    if (dataFile.is_open())
    {
        //keep reading until you are at the end of the file
        while (!dataFile.eof())
        {
            //Grab each line from the CVS separated by the carriage return character.
            getline(dataFile, currentCVSLine, '\r');
            //exclude header row
            if (rowCount != 0)
            {
                
                if (currentCVSLine.length() != 0)
                {
                    CrimeData row(currentCVSLine);
                    crimeVector.push_back(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
   else
   {
       cerr << "NO FILE" << endl;
   }
    
    return crimeVector;
}




vector<Music> FileController :: musicDataToVector(string filename)
{
    vector<Music> musicVector;
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    //if the file exists at that path
    if (dataFile.is_open())
    {
        //keep reading until you are at the end of the file
        while (!dataFile.eof())
        {
            //Grab each line from the CSV separated by the carriage return character
            getline (dataFile, currentCVSLine,'\r'); //maybe use n?
        
            //Exclude header row
            if (rowCount != 0)
            {
                //create a CrimeData instance from the line. exclude a blank line (usually if opened separately)
                if (currentCVSLine.length()  != 0)
                {
                    Music row(currentCVSLine);
                    musicVector.push_back(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
        
    }
    else{
        cerr << "NO FILE" << endl;
    }
    return musicVector;
}



LinkedList<CrimeData> FileController :: readDataToList(string fileName)
{
    LinkedList<CrimeData> crimes;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    //if the file exists at that path
    if (dataFile.is_open())
    {
        //keep reading until you are at the end of the file
        while (!dataFile.eof())
        {
            //grab each line from the CSV separated by the carriage return character
            getline(dataFile, currentCVSLine, '\n');
            //exclude header row
            if (rowCount != 0)
            {
                //create a CrimeData instance from the line. exclude a blank line (usually if opened separately)
                if (currentCVSLine.length() != 0)
                {
                    CrimeData row(currentCVSLine);
                    crimes.add(row);
                    
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
   else
   {
       cerr << "NO FILE" << endl;
   }
    return crimes;
}


LinkedList<Music> FileController :: musicDataToList(string fileName)
{
    LinkedList<Music> musicList;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    //if the file exists at that path
    if (dataFile.is_open())
    {
        //keep reading until you are at the end of the file
        while (!dataFile.eof())
        {
            //grab each line from the CSV separated by the carriage return character
            getline(dataFile, currentCVSLine, '\n');
            //exclude header row
            if (rowCount != 0)
            {
                //create a CrimeData instance from the line. exclude a blank line (usually if opened separately)
                if (currentCVSLine.length() != 0)
                {
                    Music row(currentCVSLine);
                    musicList.add(row);
                    
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return musicList;
}



Queue<Music> FileController :: musicDataToQueue(string fileName)
{
    Queue<Music> musicQueue;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if (dataFile.is_open())
    {
        while (!dataFile.eof())
        {
            getline(dataFile, currentCVSLine, '\n');
            if (rowCount != 0)
            {
                if (currentCVSLine.length() != 0)
                {
                    Music row(currentCVSLine);
                    musicQueue.add(row);
                    
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return musicQueue;
}

Stack<Music> FileController :: musicDataToStack(string fileName)
{
    Stack<Music> musicStack;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if (dataFile.is_open())
    {
        while (!dataFile.eof())
        {
            getline(dataFile, currentCVSLine, '\n');
            if (rowCount != 0)
            {
                if (currentCVSLine.length() != 0)
                {
                    Music row(currentCVSLine);
                    musicStack.add(row);
                    
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return musicStack;
}


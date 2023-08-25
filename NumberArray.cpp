//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 11A
//        Date: 5/16/2023
// Description: This is the implementation file, which contains the method definitions for 11A.cpp
//************************************************************************************************************

#include <iostream>
#include "NumberArray.hpp"
using namespace std;

// constructor
NumberArray::NumberArray(int s)
{
    arrayPointer = nullptr;
    arrayPointer = new double [s];
    size = s;
}

// destructor
NumberArray::~NumberArray()
{
    if (arrayPointer != nullptr)
    {
        delete[] arrayPointer;
        arrayPointer = nullptr;
    }
}

// getCell function
int NumberArray::getCell(int cellNum)
{
    if (cellNum < 0 || cellNum > size)
    {
        cout << "Invalid cell number.\n";
        exit(EXIT_FAILURE);
    }

    return arrayPointer[cellNum];
}

// setCell function
void NumberArray::setCell(int c, double val)
{
    if (arrayPointer != nullptr && c >= 0 && c <= size)
        arrayPointer[c] = val;
    
    else
    {
        cout << "Invalid cell number.\n";
        exit(EXIT_FAILURE);
    }
}

// getAverage function 
// calculates the average of all user entered numbers
double NumberArray::getAverage()
{
    double total = 0;

    for (int count = 0; count < size; count++)
    {
        total += arrayPointer[count];
    }

    return total / size;
}

// getHighest function
// finds the highest number of all user entered numbers
double NumberArray::getHighest()
{
    double highest = arrayPointer[0];

    for (int count = 1; count < size; count++)
    {
        if (arrayPointer[count] > highest)
            highest = arrayPointer[count];
    }

    return highest;
}

// getLowest function
// finds the lowest number of all user entered numbers
double NumberArray::getLowest()
{
    double lowest = arrayPointer[0];

    for (int count = 1; count < size; count++)
    {
        if (arrayPointer[count] < lowest)
            lowest = arrayPointer[count];
    }

    return lowest;
}

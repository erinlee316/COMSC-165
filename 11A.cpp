//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 11A
//        Date: 5/16/2023
// Description: Program uses classes to accept integer arguments and free memory held in array. Member functions will store values,
//              retrieve values, return highest, lowest, and average values
//************************************************************************************************************

#include <iostream>
#include "NumberArray.cpp"
#include "NumberArray.hpp"
using namespace std;

int main()
{
    // declare and initialize variables
    int quantity = 0;
    int count = 0;
    double value = 0;

    // user input for how many values to store
    cout << "Enter the quantity of numbers you want to store: ";
    cin >> quantity;

    // create NumberArray object
    NumberArray numbers(quantity);

    // display and use for loop to get user input
    cout << "\nEnter " << quantity << " numbers:" << endl;
    for (count = 0; count < quantity; count++)
    {
        cout << "Number " << count + 1 << ": ";
        cin >> value;

        // store value in object
        numbers.setCell(count, value);
    }

    // display all values
    cout << "\nUser entered numbers:" << endl;
    for (count = 0; count < quantity; count++)
    {
        cout << "Number " << count + 1 << ": "
             << numbers.getCell(count) << endl;
    }

    // display average value from user input
    cout << "\nAverage number: ";
    cout << numbers.getAverage() << endl;

    // display highest value from user input
    cout << "Highest number: ";
    cout << numbers.getHighest() << endl;

    // display lowest value from user input
    cout << "Lowest number: ";
    cout << numbers.getLowest() << endl;

    return 0;
}

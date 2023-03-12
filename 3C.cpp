//*******************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 3C
//        Date: 2/18/2023
// Description: Program modified all arrays to vectors. Program tests a function comparing the contents of two int vectors.
//*******************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;

// Function prototype
bool testPIN(const vector<int>, const vector<int>, int);

int main ()
{
    const int NUM_DIGITS = 7; // Number of digits in a PIN
    vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0}; // Base set of values.
    vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0}; // Only 1 element is different from pin1.
    
    vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7}; // All elements are different from pin1.
    
    // determines if array elements for pin1 and pin2 are the same
    if (testPIN(pin1, pin2, NUM_DIGITS))
        cout << "ERROR: pin1 and pin2 report to be the same.\n";
   
    else
        cout << "SUCCESS: pin1 and pin2 are different.\n";
    
    // determines if array elements for pin1 and pin3 are the same
    if (testPIN(pin1, pin3, NUM_DIGITS))
        cout << "ERROR: pin1 and pin3 report to be the same.\n";
    
    else
        cout << "SUCCESS: pin1 and pin3 are different.\n";
    
    // determines if array elements for pin1 and pin1 are the same
    if (testPIN(pin1, pin1, NUM_DIGITS))
        cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
    
    else
        cout << "ERROR: pin1 and pin1 report to be different.\n";
    
    return 0;
}


//******************************************************************
// The following function accepts two int arrays. The arrays are *
// compared. If they contain the same values, true is returned. *
// If the contain different values, false is returned. *
//******************************************************************

bool testPIN(const vector<int> custPIN, const vector<int> databasePIN, int size)
{
    // for loop checks to see if the elements of two arrays have the same values
    for (int index = 0; index < size; index++)
    {
        if (custPIN.at(index) != databasePIN.at(index))
            return false; // We've found two different values.
    }

    return true; // If we make it this far, the values are the same.
}

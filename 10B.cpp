//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 10A
//        Date: 5/6/2023
// Description: Program uses recusives to calculate the greatest common factor of two numbers. User can only enter positive 
//              numbers, and the program will terminate if they enter -1 for first number.
//************************************************************************************************************

#include <iostream>
using namespace std;

// function prototypes
int gcf(int, int);
void getNumbers(int&, int&);

int main()
{
    // declare and initialize variables
    int first = 0;
    int second = 0;
    int gcfactor = 0;
    char choice;

    // program required to run once
    do
    {
        // display and get user input
        cout << "Enter two values to determine the greatest common factor" << endl;
        cout << "(Positive numbers only. Enter -1 for Value 1 to quit)" << endl;
        getNumbers(first, second);

        // function call
        gcfactor = gcf(first, second);

        // program ends if user enters -1
        if (first == -1)
        {
            cout << "Program ending..." << endl;
            return 0;
        }

        // display gcf
        cout << "\nThe greatest common factor of " << first << " and " << second << " is " << gcfactor;

        // asks user if they want to enter another number
        cout << "\nWould you like to continue (Y/N)?" << endl;
        cin >> choice;
        cout << endl;
    }

    // keeps looping until user input is not 'Y'
    while (toupper(choice) == 'Y');

    return 0;
}


// function gets values for first and second variables
void getNumbers(int &first, int &second)
{
    // get user input 
    cout << "Value 1: ";
    cin >> first;

    // leaves function if user enters -1
    if (first == -1)
        return;

    // keeps looping
    while (first < 0)
    {
        cout << "\nInvalid input. Try again (positive numbers only)" << endl;
        cout << "Value 1: ";
        cin >> first;
    }

    // get user input 
    cout << "Value 2: ";
    cin >> second;

    while (second < 0)
    {
        cout << "\nInvalid input. Try again (positive numbers only)" << endl;
        cout << "Value 2: ";
        cin >> second;
    }
}


// function calculates remainder to find the greatest common factor between two numbers
int gcf(int first, int second)
{
    // declare variable
    int remainder;

    // keeps calling itself until there is no more remainder
    if (second != 0)
    {   
        // takes the remainder after dividing the two numbers
        remainder = first % second;

        // calls itself to keep finding greatest common factor
        return gcf (second, remainder);
    }

    else
        return first;
}
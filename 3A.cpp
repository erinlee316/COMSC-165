//*******************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 3A
//        Date: 2/16/2023
// Description: Program asks user to enter temperatures based on the number of days the user picks. A function will sort the user's input from ascending order and output the average of the total temperatures.
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

// function prototype
void tempInput(int[], int);
void ascendingOrder(int[], int);
double averageTemp(int[], int, double, double);

int main()
{
    // declare and initialize variables
    const int MAXDAYS = 10;
    int temperature[MAXDAYS];
    int userDays = 0;
    double average = 0;
    double total = 0;
    
    cout << "Input the number of temperatures to be read (no more than 10)" << endl;
    cin >> userDays;
    
    // keeps asking user input until user enters valid number
    while (userDays < 1 || userDays > MAXDAYS)
    {
        cout << "Invalid input. Input the number of temperatures to be read (no more than 10)" << endl;
        cin >> userDays;
    }
        
    // function calls
    tempInput(temperature, userDays);
    ascendingOrder(temperature, userDays);
    
    // display average of all temperatures
    cout << "Average temperature for " << userDays << " days is " << fixed << setprecision(2)
    << averageTemp(temperature, userDays, total, average) << " degrees" << endl;
    
    return 0;
}


// function takes in user input for temperature
void tempInput(int temp[], int day)
{
    // for loop assigns user input into temperature array
    for (int i = 0; i < day; i++)
    {
        cout << "Enter temperature for day " << i + 1 << ": " << endl;
        cin >> temp[i];
    }
}


// function sorts temperatures in ascending order using bubble sort
void ascendingOrder(int temp[], int day)
{
    // declare and initialize variable
    int swap;
    
    // first element used in bubble sort
    for (int i = 0; i < day; i++)
    {
        // second element used in bubble sort
       for (int j = i + 1; j < day; j++)
       {
            // statement compares two adjacent elements and swaps their values if first element is larger than second element
            if (temp[i] > temp[j])
            {
                swap = temp[j];
                temp[j] = temp[i];
                temp[i] = swap;
            }
        }
    }
    
    // displays elements from smallest to largest value
    cout << "Sorted element list by ascending order" << endl;
    for (int k = 0; k < day; k++)
    {
        cout << temp[k] << " ";
    }
    
    cout << endl;
}


// function definition calculates average temperature
double averageTemp(int temp[], int day, double totalTemp, double averageTemp)
{
    // initialize variable
    totalTemp = 0;
    averageTemp = 0;
    
    // for loop adds up total temperature
    for (int i = 0; i < day; i++)
    {
        totalTemp += temp[i];
    }
    
    // calculates the average of all temperatures
    averageTemp = totalTemp / day;
    
    return averageTemp;
}


/*
 void averageTemp(int temp[], int day, double totalTemp, double &averageTemp)
 {
     // initialize variable
     totalTemp = 0;
     averageTemp = 0;
     
     // for loop adds up total temperature
     for (int i = 0; i < day; i++)
     {
         totalTemp += temp[i];
     }
     
     // calculates the average of all temperatures
     averageTemp = totalTemp / day;
 */

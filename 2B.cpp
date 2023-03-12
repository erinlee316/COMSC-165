//*********************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 2B
//        Date: 2/10/2023
// Description: Program asks user to enter input for miles and hours traveled, and function will calculate user's speed
//*********************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

// function prototype
void calculation(double, double, double&);

int main()
{
    // declare and initialize variables
    double distance = 0.0;
    double time = 0.0;
    double speed = 0.0;
    
    // ask for user input
    cout << "Please input the miles traveled" << endl;
    cin >> distance;
    
    cout << "Please input the hours traveled" << endl;
    cin >> time;
    
    // function call
    calculation(distance, time, speed);
    
    // output results from function call
    cout << "Your speed is " << fixed << setprecision(2) << speed << " miles per hour" << endl;
    
    return 0;
}

// function definition
void calculation(double miles, double hours, double &milesPerHour)
{
    // calculate how many miles user travels per hour
    milesPerHour = miles / hours;
}

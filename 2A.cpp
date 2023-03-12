// ************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 2A
//        Date: 2/9/2023
// Description: Program asks user to enter two numbers and exchange function will swap the value of the numbers.
//************************************************************************************************************

#include <iostream>
using namespace std;

// function prototype
void exchange(float&, float&);

int main()
{
    
    // declare and initialize variables
    float first = 0.0;
    float second = 0.0;
    
    // ask for user input
    cout << "Enter the first number" << endl;
    cout << "Then hit enter" << endl;
    cin >> first;
    cout << "Enter the second number" << endl;
    cout << "Then hit enter" << endl;
    cin >> second;

    // display two numbers that user entered
    cout << "You input the numbers as " << first << " and " << second << "." << endl;
    
    // function call
    exchange(first, second);
    
    // display results after swapping number values
    cout << "After swapping, the first number has the value " << first << " which was the value of the second number" << endl;
    cout << "The second number has the value of " << second << " which was the value of the first number" << endl;
    
    return 0;
}


// function definition
void exchange(float &number1, float &number2)
{
    // declare and initialize variables
    float swappingNum = 0.0;
    
    // first and second number swap
    swappingNum = number1;
    number1 = number2;
    number2 = swappingNum;
}

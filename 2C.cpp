//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 2C
//        Date: 2/11/2023
// Description: Program asks user to enter how many grades they have and the numeric value of each grade, then the function will calculate the average and the program will determine the user's letter grade
//************************************************************************************************************

#include <iostream>
using namespace std;

// function prototype
void calculateAverage(double&, double, int);

int main()
{
    // declare and initialize variables
    int grades = 0;
    double numberGradeValue = 0;
    double totalGrade = 0;
    double averageGrade = 0;
    char letterGrade;
    
    // ask for user input
    cout << "Enter the number of grades" << endl;
    cin >> grades;
    
    // for loop asks for values of user's grades depending on the number of grades user has
    for (int i = 0; i < grades; i++)
    {
        cout << "Enter a numeric grade between 0-100" << endl;
        cin >> numberGradeValue;
        
        // while loop continues to ask for user input until user enters value between 0-100
        while (numberGradeValue > 100 || numberGradeValue < 0)
        {
            cout << "Invalid input. Enter a numeric grade between 0-100" << endl;
            cin >> numberGradeValue;
        }
        
        // adds number grades together and stores in one variable
        totalGrade += numberGradeValue;
    }

    // function call
    calculateAverage(averageGrade, totalGrade, grades);

    // determines the user's letter grade based on their average grade
    if (averageGrade >= 90)
        letterGrade = 'A';
        
    else if (averageGrade >= 80)
        letterGrade = 'B';
        
    else if (averageGrade >= 70)
        letterGrade = 'C';
    
    else if (averageGrade >= 60)
        letterGrade = 'D';
    
    else
        letterGrade = 'F';
    
    // display user's final letter grade
    cout << "The grade is " << letterGrade << endl;

    return 0;
}


// function definition
void calculateAverage(double &average, double total, int numGrades)
{
    // calculate average of user's grades
    average = total / numGrades;
}

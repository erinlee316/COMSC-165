// ************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 1B
//        Date: 2/3/2023
// Description: Program calculates and displays the total sick days based on how many tellers are sick over the last three years.
// ************************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    
    // declare and initialize variables
    int sickDays = 0;
    int numTellers = 0;
    int numYears = 0;
    int totalDays = 0;
    
    // display and asks user the number of tellers working at bank
    cout << "How many tellers worked at Nation's Bank during each of the last three years ?" << endl;
    cin >> numTellers;
    
    // while loop asks user for input if they put negative numbers or zero value
    while (numTellers <= 0)
    {
        cout << "Invalid input" << endl;
        cout << "How many tellers worked at Nation's Bank during each of the last three years ?" << endl;
        cin >> numTellers;
    }
    
    // for loop questions each teller after nested for loop finishes execution
    for (int i = 0; i < numTellers; i++)
    {
        
        // nested for loop asks teller three times how often they were sick every year
        for (numYears = 0; numYears < 3; numYears++)
        {
            cout << "How many days was teller " << i + 1 << " out sick during year " << numYears + 1 << " ?" << endl;
            cin >> sickDays;
            
            // calculates total number of days that all tellers were sick
            totalDays += sickDays;
        }
    }
    
    // display number of tellers and total of sick days
    cout << "The " << numTellers << " tellers were out sick for a total of " << totalDays << " days during the last three years" << endl;
    
    return 0;
}

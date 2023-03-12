// ************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 1A
//        Date: 2/1/2023
// Description: Program takes a tally survey on the user's favorite beverages. The program keeps running until user enters -1
// ************************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    
    // declare and initialize variables
    int userInput = 0;
    int coffee = 0;
    int tea = 0;
    int coke = 0;
    int orange = 0;
    int person = 0;
    
    // display what numbers corresponds to what beverages
    cout << "1. Coffee  2. Tea  3. Coke  4. Orange Juice" << endl;
    
    // while loop continues to ask for user input until user enters -1
    while (userInput != -1)
    {
        cout << "Please input the favorite beverage of person #" << person + 1 << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << endl;
        
        cin >> userInput;
        
        // switch increments the variables for different beverages depending on user input
        switch (userInput)
        {
            case 1:
                coffee += 1;
                break;
            
            case 2:
                tea += 1;
                break;
            
            case 3:
                coke += 1;
                break;
            
            case 4:
                orange += 1;
                break;
                
            case -1:
                break;
                    
            // display if user does not input 1, 2, 3, 4, or -1
            default:
                cout << "Invalid input" << endl;
                break;
        }
        
        // increments after each input to keep track of how many people get surveyed
        person += 1;
    }
    
    // display survey results
    cout << "The total number of people surveyed is " << person - 1 << ". The results are as follows:" << endl;
    cout << "Beverage Number of Votes" << endl;
    cout << "*********************************" << endl;
    cout << "Coffee " << coffee << endl;
    cout << "Tea " << tea << endl;
    cout << "Coke " << coke << endl;
    cout << "Orange Juice " << orange << endl;

    return 0;
}

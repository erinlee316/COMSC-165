//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 7A
//        Date: 4/14/2023
// Description: Program asks user to input 10 soccer player names, and user can choose five options. Program searches for a soccer player's data by searching full or some parts of their last name. Player's full name and date of birth will display if information is found.
//************************************************************************************************************

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// constant variable
const int MAX_PLAYERS = 10;
const int MAX_NAME = 20;

// define structure 
struct Soccer
{
    char lastName[MAX_NAME];
    char firstName[MAX_NAME];
    int birthMonth;
    int birthDay;
    int birthYear;
};

// function prototypes
void getInformation(Soccer[]);
void makeCopy(const Soccer[], Soccer[]);
void displayOriginal(const Soccer[]);
void sortByLastName(Soccer[]);
void flip(Soccer &, Soccer &);
void displaySortedData(Soccer[]);
void findPlayer(Soccer[]);
int searchByLastName(const Soccer[], char[]);

int main()
{
        
    
    // declare and initialize variables
    Soccer player[MAX_PLAYERS];
    Soccer playerCopy[MAX_PLAYERS];
    int option = 0;
    
    // function calls to get information of soccer players
    getInformation(player);
    
    // function calls to make a copy of data
    makeCopy(player, playerCopy);
        
        do
        {
            cout << "Choose an option:" << endl;
            cout << "(1 - display original data, 2 - sort data by last name," << endl;
            cout << "3 - display sorted data, 4 - search by last name, 5 - exit the program)" << endl;
            cin >> option;
            cout << endl;
            
            while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
            {
                cout << "Invalid input. Try again" << endl;
                cin >> option;
                cout << endl;
            }
            
            // switch function takes user through menu options based on number they input
            switch(option)
            {
                case 1:
                    displayOriginal(player);
                    cout << endl;
                    break;
                    
                case 2:
                    sortByLastName(playerCopy);
                    break;
                    
                case 3:
                    displaySortedData(playerCopy);
                    cout << endl;
                    break;
                    
                case 4:
                    findPlayer(playerCopy);
                    cout << endl;
                    break;
                    
                case 5:
                    cout << "Thank you for using this program" << endl;
                    break;
                    
                default:
                    cout << "Invalid input. Try again" << endl;
                    cin >> option;
            }
        }
        
        while (option != 5);
    
    return 0;
}


// function gets information about each soccer player
void getInformation(Soccer playerData[])
{
    // display information
    cout << "Enter data for ten soccer players separated by a space" << endl;
    cout << "(last name, first name, birth month, birth day, and birth year)" << endl;
    cout << endl;
    
    // for loop takes in a player's last name, first name, and date of birth
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        cin >> playerData[i].lastName
            >> playerData[i].firstName
            >> playerData[i].birthMonth
            >> playerData[i].birthDay
            >> playerData[i].birthYear;
    }
    
    cout << endl;
}


// function copies the original data and assigns it to a new variable
void makeCopy(const Soccer playerData[], Soccer copyData[])
{
    // for loop assigns all data into a new variable
    for (int i = 0; i < MAX_PLAYERS; i++)
        copyData[i] = playerData[i];
}


// function displays original, unsorted data for each soccer player
void displayOriginal(const Soccer playerData[])
{
    cout << "Unsorted data:" << endl;
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        cout << playerData[i].lastName << " "
             << playerData[i].firstName << " "
             << playerData[i].birthMonth << " "
             << playerData[i].birthDay << " "
             << playerData[i].birthYear << endl;
    }
}


// function uses bubble sort to sort the last names in alphabetical order
void sortByLastName(Soccer playerData[])
{
    // compares one player's last name
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        // compares the next player's last name
        for (int j = i + 1; j < MAX_PLAYERS; j++)
        {
            // statement determines if second player's last name comes first
            if (strcmp(playerData[i].lastName, playerData[j].lastName) > 0)
                
                // function called to swap the order of first and second player's last names
                flip(playerData[i], playerData[j]);
        }
    }
}


// function swaps data of two soccer players
void flip(Soccer &playerData, Soccer &playerData2)
{
    // declare and initialize variable
    Soccer random;
    
    random = playerData;
    playerData = playerData2;
    playerData2 = random;
}


// function displays sorted data in alphabetical order
void displaySortedData(Soccer playerData[])
{
    cout << "Sorted data:" << endl;
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        cout << playerData[i].lastName << " "
             << playerData[i].firstName << " "
             << playerData[i].birthMonth << " "
             << playerData[i].birthDay << " "
             << playerData[i].birthYear << endl;
    }
}


// function searches for last name based on user input
void findPlayer(Soccer playerData[])
{
    char ending[MAX_NAME] = "//";
    char name[MAX_NAME];
        
    cout << "Enter one or more starting letters of the last name" << endl;
    cout << "( enter '//' to quit this option)" << endl;
    cin >> name;
    
    // determines whether user input is "//" or not
    while (strcmp(name, ending) != 0)
    {
        
        int index = searchByLastName(playerData, name);

        // display information if name matches with data
        if (index != -1)
        {
            cout << playerData[index].lastName << " "
                 << playerData[index].firstName << " "
                 << playerData[index].birthMonth << " "
                 << playerData[index].birthDay << " "
                 << playerData[index].birthYear << " " << endl;
    
        }
        
        // display if name does not match with data
        else
            cout << "Not found" << endl;
        
        cout << endl;
        cout << "Enter one or more starting letters of the last name" << endl;
        cout << "( enter '//' to quit this option)" << endl;
        cin >> name;
    }
}


int searchByLastName(const Soccer playerData[], char inputName[])
{
    // loop goes through entire list of soccer players until it finds a match
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        // statement determines if user's input is found in the soccer player data
        if (strncmp(playerData[i].lastName, inputName, strlen(inputName)) == 0)
            return i;
    }
    
    // player not found
    return -1;
}

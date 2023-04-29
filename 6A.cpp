//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 6A
//        Date: 3/17/2023
// Description: Program asks user to enter a string, then user can edit their string by searching, inserting, appending, deleting, or replacing phrases
//************************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

// global variable
const int SIZE = 100;

// function prototypes
int find(char[], char[]);
void search(char[]);
void insert(char[]);
void append(char[]);
void deletes(char[]);
void replace(char[]);

int main()
{
    // declare and initialize variables
    char charInput;
    char stringInput[SIZE];
    string options = "(s - search, i - insert, a - append, d - delete, r - replace, e - exit)";
    
    // asks user for input and displays user input
    cout << "Enter a string: ";
    cin.getline(stringInput, SIZE);
    cout << endl;
    cout << "Choose an option" << endl;
    cout << options << ": ";
    cin >> charInput;
    cout << endl;
    cin.ignore();

    // keeps getting user input until user enters character 'e'
    while (charInput != 'e')
    {
        switch (charInput)
        {
            case 's':
                search(stringInput);
                cout << endl;
                break;

            case 'i':
                insert(stringInput);
                cout << endl;

                break;

            case 'a':
                append(stringInput);
                cout << endl;
                break;

            case 'd':
                deletes(stringInput);
                cout << endl;
                break;

            case 'r':
                replace(stringInput);
                cout << endl;
                break;

            default:
                cout << "Invalid input" << endl;
                cout << endl;
                break;
        }

        cout << "Choose an option" << endl;
        cout << options << ": ";
        cin >> charInput;
        cin.ignore();
    }
    
    cout << "Bye" << endl;

    return 0;
}

// function searches new string in current string to determine if phrase is found in both strings
int find(char originalString[], char newString[])
{
    // declare and initialize variables
    long newLength;
    long originalLength;
    int returnValue;
    int index = -1;
    
    originalLength = strlen(originalString);
    newLength = strlen(newString);

    // loop compares two strings character by character and stops looping if there is a match
    for (int i = 0; i < (originalLength - (newLength - 1)); i++)
    {
        returnValue = strncmp(&originalString[i], newString, newLength);
        
        // assigns index to number if string is found
        if (returnValue == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}


// function allows user to search for phrase in current string
void search(char userInput[])
{
    // declare and initialize variables
    char toSearch[SIZE];
    int index = 0;

    // asks for user input and calls function to find index of string
    cout << "Enter a string to be searched: ";
    cin.getline(toSearch, SIZE);
    index = find(userInput, toSearch);

    // prints if word is found in string
    if (index != -1)
        cout << "The searched string is located at index " << index << endl;

    // print if word is not found in string
    else
        cout << "The searched string cannot be found" << endl;
}


// function allows user to insert phrase at specific index
void insert(char userInput[])
{
    // declare and initialize variable
    char toInsert[SIZE];
    char random[SIZE];
    char empty[SIZE] = " ";
    int index = 0;
    long originalLength;
    
    originalLength = strlen(userInput);

    // asks for user input
    cout << "Enter a string to be inserted: ";
    cin.getline(toInsert, SIZE);

    cout << "Enter the index of where string should be inserted: ";
    cin >> index;
    cin.ignore();
    
    while (index < 0 || index > originalLength)
    {
        cout << "Invalid index. Enter the index of where string should be inserted: ";
        cin >> index;
        cin.ignore();
    }

    // copies and appends strings at specific index of current string
    strcpy(random, &userInput[index]);
    userInput[index] = '\0';
    strcat(userInput, empty);
    strcat(userInput, toInsert);
    strcat(userInput, random);

    // displays updated string
    cout << "Updated string: " << userInput << endl;
}


// function allows user to add a phrase onto current string
void append(char userInput[])
{
    // declare and initialize variables
    char toAppend[SIZE];
    char empty[SIZE] = " ";

    // asks for user input
    cout << "Enter a string to be appended: ";
    cin.getline(toAppend, SIZE);

    // adds and displays user input at the end of original string
    strcat(userInput, empty);
    strcat(userInput, toAppend);
    cout << "Updated string: " << userInput << endl;
}


// function allows user to delete phrase from current string
void deletes(char userInput[])
{
    // declare and initialize variables
    char toDelete[SIZE];
    char random[SIZE];
    int index = 0;

    // asks for user input
    cout << "Enter a string to be deleted: ";
    cin.getline(toDelete, SIZE);

    index = find(userInput, toDelete);

    // deletes specific phrase if string is found and displays updated string
    if (index != -1)
    {
        strcpy(random, &userInput[index + strlen(toDelete)]);
        userInput[index] = '\0';
        strcat(userInput, random);
        cout << "Updated string: " << userInput << endl;
    }

    // display if specific phrase is not found
    else
        cout << "The searched string cannot be found" << endl;
}



// function replaces specific phrase from current string
void replace(char userInput[])
{
    // declare and initialize variables
    char toReplace[SIZE];
    char newString[SIZE];
    char random[SIZE];
    char empty[SIZE] = " ";
    int index = 0;

    // asks for user input
    cout << "Enter a string to be replaced: ";
    cin.getline(toReplace, SIZE);

    cout << "Enter a string to replace old string: ";
    cin.getline(newString, SIZE);

    index = find(userInput, toReplace);

    // replaces old string if specific string is found and displays updated string
    if (index != -1)
    {
        strcpy(random, &userInput[index + strlen(toReplace)]);
        userInput[index] = '\0';
        strcat(userInput, empty);
        strcat(userInput, newString);
        strcat(userInput, random);
        cout << "Updated string: " << userInput << endl;
    }

    // display if specific string is not found
    else
        cout << "The searched string cannot be replaced" << endl;
}

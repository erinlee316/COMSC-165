//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 6B
//        Date: 3/18/2023
// Description: Program asks user to enter a string, then functions translates the word into Pig Latin by removing leading spaces, removing and appending the first letter, and appending "ay".
//************************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

// function prototype
string leftTrim(string);
string popWord(string &);
string pigTranslation(string);

int main()
{
    // declare and initialize variables
    string userInput;
    string pigLatin;
    string word;
    
    // ask for user input
    cout << "Enter a string: ";
    getline(cin, userInput);
    
    // display original string from user
    cout << "English: " << userInput << endl;
    
    // keeps looping until string no longer has characters
    while (userInput.size() > 0)
    {
        // calls functions to get individual word from original string and translate it into Pig Latin
        word = popWord(userInput);
        word = pigTranslation(word);
        
        // adds individual word from popWord function onto new string
        pigLatin = (pigLatin + (word + " "));
    }
    
    // display translated string
    cout << "Pig Latin: " << pigLatin << endl;
    
    return 0;
}


// function removes all leading spaces in string
string leftTrim(string userString)
{
    // deletes leading spaces found before words
    while (userString[0] == ' ')
        userString.erase(0, 1);
        
    return userString;
}


// function focuses on each word separately and manipulates string
string popWord(string &userString)
{
    // declare and initialize variable
    int i = 0;
    string word;
    
    // calls function to trim spaces at beginning of word
    userString = leftTrim(userString);
    
    // keeps looping until space if found or end of string is reached
    while (userString[i] != ' ' && i < userString.size())
        i++;
    
    // new string starts without space until i index
    word = userString.substr(0, i);
    
    // deletes word from original string
    userString.erase(0, i);
    
    return word;
}


// function translates string into Pig Latin
string pigTranslation(string userString)
{
    // declare and initialize variables
    char first = userString[0];
    
    // appends first character and deletes it from original word
    userString.append(1, first);
    userString.erase(0, 1);

    // appends "ay" to the end of word
    userString.append("ay");

    return userString;
}

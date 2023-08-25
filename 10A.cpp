//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 10A
//        Date: 5/6/2023
// Description: Program uses recusives to determine if a string is a palidrome. The function will keep calling
//              itself if the letters match from beginning to end.
//************************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

// function prototype
bool isPalindrome(string, int, int);

int main() 
{
    // declare and initialize variables
    string word;
    char choice;
    int firstLetter = 0;
    int lastLetter = 0;

    // program required to run once
    do
    {
        // get user input
        cout << "Enter a word or phrase: ";
        getline(cin, word);

        // initialize variable 
        lastLetter = word.length() - 1;

        // statement displays if word is a palindrome
        if (isPalindrome(word, firstLetter, lastLetter))
            cout << "'" << word << "' is a palindrome." << endl;

        // statement displays if word is not a palindrome
        else 
            cout << "'" << word << "' is NOT a palindrome." << endl;

        // asks user if they want to enter another word
        cout << "\nWould you like to continue (Y/N)?" << endl;
        cin >> choice;
        cout << endl;
        cin.ignore();
    } 
    
    // keeps looping until user input is not 'Y'
    while (toupper(choice) == 'Y');

    return 0;
}


// function determines if word entered by user is a palindrome
bool isPalindrome(string userInput, int first, int last)
{
    // declare and initialize variable
    bool isPal = false;

    // returns true if first and last variables match index for odd lettered words 
    // or the index of first is greater than last for even lettered words
    if (first >= last)
        isPal = true;

    // returns itself if letter at index first and last match
    else if (userInput[first] == userInput[last])
        isPal = isPalindrome(userInput, first + 1, last - 1);
    
    return isPal;
}
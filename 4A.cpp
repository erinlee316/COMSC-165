//*******************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 4A
//        Date: 2/24/2023
// Description: Program asks user to enter however many elements they want (less than 50). Functions will display user's array values, sort the user's input using selection sort, find a specific number using binary sort, and output the mean of the total elements.
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void displayData(int[], int);
void selectionSort(int[], int);
int binarySearch(int[], int, int);
double mean(int[], int);

int main()
{
    // declare and initialize variables
    const int MAXELEMENTS = 50;
    int arr[MAXELEMENTS];
    int numElements = 0;
    int userInput = 0;
    int searchNum = 0;

    // ask for user input
    cout << "Enter number of elements wanted (less than 50): ";
    cin >> numElements;
    
    // keeps asking user input until user enters valid number
    while (numElements < 0 || numElements > MAXELEMENTS)
    {
        cout << "Invalid input. Enter number of elements wanted (less than 50): ";
        cin >> numElements;
    }
    
    // asks user to enter each value of array
    cout << endl;
    for (int i = 0; i < numElements; i++)
    {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> userInput;
        arr[i] = userInput;
    }
    
    // display information and call functions
    cout << endl;
    cout << "Size of array: " << numElements << endl;
    cout << "Unsorted array list: ";
    displayData(arr, numElements);
    selectionSort(arr, numElements);
    cout << "Sorted array list: ";
    displayData(arr, numElements);

    // ask for user input
    cout << endl;
    cout << "Enter a number you want to find: ";
    cin >> searchNum;
    
    // display if specific value is not found in array
    if (binarySearch(arr, numElements, searchNum) == -1)
        cout << "Value " << searchNum << " was not found in array" << endl;
    
    // display if specific value is found in array
    else
        cout << "Value " << searchNum << " was found at index " << binarySearch(arr, numElements, searchNum) << endl;
    
    // display mean
    cout << "The mean is " << fixed << setprecision(2) << mean(arr, numElements) << endl;
    
    return 0;
}


// function displays array (unsorted/sorted)
void displayData(int array[], int elements)
{
    // for loop displays each element
    for (int i = 0; i < elements; i++)
        cout << array[i] << " ";
    cout << endl;
}


// function sorts array values using selection sort
void selectionSort(int array[], int elements)
{
    // declare and initialize variable
    int smallestValue = 0;
    int smallestIndex = 0;
    
    // for loop moves through entire array
    for (int j = 0; j < elements - 1; j++)
    {
        // makes current element the smallest value
        smallestValue = array[j];
        smallestIndex = j;
        
        // nested for loop finds smallest value in remaining array
        for (int k = j + 1; k < elements; k++)
        {
            // statement compares whether there is a smaller number than the current smallest value
            if (smallestValue > array[k])
            {
                smallestValue = array[k];
                smallestIndex = k;
            }
        }
        
        // swaps values of two elements
        array[smallestIndex] = array[j];
        array[j] = smallestValue;
    }
}


// function performs binary search on array
int binarySearch(int array[], int index, int userNum)
{
    // declare and initialize variables
    int middle = 0;
    int left = 0;
    int right = index - 1;
    int position = -1;
    bool found = false;
    
    // loop keeps going while left index is less than or equal to right index
    while (!found && left <= right)
    {
    
        // calculates number of middle index
        middle = (left + right) / 2;
    
        // determines if array contains specific number at middle index
        if (array[middle] == userNum)
        {
            found = true;
            position = middle;
        }
    
        // searches for specific value in lower half of array
        else if (userNum < array[middle])
            right = middle - 1;
    
        // searches for specific value in upper half of array
        else
            left = middle + 1;
    }

    return position;
}


// function calculates mean of array
double mean(int array[], int elements)
{
    // declare and initialize variables
    double meanValue = 0;
    double total = 0;
    
    // for loop adds all elements together
    for (int i = 0; i < elements; i++)
    {
        total += array[i];
    }
    
    // calculates average of total
    meanValue = total / elements;
    
    return meanValue;
}

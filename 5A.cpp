//*******************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 5A
//        Date: 3/10/2023
// Description: Program asks user to enter the number of movies college students see in one month. Functions will sort the elements from the array in ascending order and display the average, median, and mode from the data set.
//*******************************************************************************************************

#include <iostream>
using namespace std;

// function prototype
void dataCollection(int*, int);
void selectionSort(int*, int);
double average(int*, int);
double median(int*, int);
int mode(int*, int);

int main()
{
    // declare and initialize variables
    int *moviePtr;
    int students = 0;
    
    // asks user to input number of students surveyed
    cout << "Enter how many students were surveyed: ";
    cin >> students;
    
    // keeps asking for user input if user puts invalid input
    while (students < 0)
    {
        cout << "Invalid input. Enter how many students were surveyed: ";
        cin >> students;
    }
    cout << endl;
    
    // array can access dynamically allocated memory
    moviePtr = new int[students];

    // function calls get and sort data
    dataCollection(moviePtr, students);
    selectionSort(moviePtr, students);
    
    // display statistics
    cout << "Results for the number of movies college students see in one month" << endl;
    cout << "Average: " << average(moviePtr, students) << endl;
    cout << "Median: " << median(moviePtr, students) << endl;
   
    // display if no mode
    if (mode(moviePtr, students) == -1)
        cout << "There is no mode in data" << endl;
    
    // display if mode exists
    else
        cout << "Mode: " << mode(moviePtr, students) << endl;
    
    // deallocates memory pointed to by pointer
    delete [] moviePtr;
    moviePtr = 0;
    
    return 0;
}


// function collects data for survey
void dataCollection(int *arr, int numStudents)
{
    // display statement
    cout << "Enter the number of movies each student saw" << endl;
    
    // for loop gets value of each element
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> *(arr + i);
        
        // keeps asking for user input if user puts invalid input
        while (*(arr + i) < 0)
        {
            cout << "Invalid input. Enter positive value" << endl;
            cout << "Student " << i + 1 << ": ";
            cin >> *(arr + i);
        }
    }
    
    cout << endl;
}


// function sorts array values in ascending order using selection sort
void selectionSort(int *arr, int numStudents)
{
    // declare and initialize variables
    int smallestValue = 0;
    int smallestIndex = 0;
    
    // for loop moves through entire array
    for (int i = 0; i < numStudents - 1; i++)
    {
        // makes current element the smallet value
        smallestValue = *(arr + i);
        smallestIndex = i;
        
        // nested for loop finds smallest value in remaining array
        for (int j = i + 1; j < numStudents; j++)
        {
            // determines if current value is smaller than the current smallest value
            if (*(arr + j) < smallestValue)
            {
                smallestValue = *(arr + j);
                smallestIndex = j;
            }
        }
        // swaps values of two elements
        *(arr + smallestIndex) = *(arr+ i);
        *(arr + i) = smallestValue;
    }
}


// function determines the average of all elements
double average(int *arr, int numStudents)
{
    // declare and initialize variables
    double sum = 0;
    double aveValue;
    
    // for loop adds up total values from all students
    for (int i = 0; i < numStudents; i++)
        sum += *(arr + i);
    
    // calculates average number of sum variable
    aveValue = sum / numStudents;
    
    return aveValue;
}


// function determines the middle value of all elements
double median(int *arr, int numStudents)
{
    // declare and initialize variables
    int middle;
    double medValue;
    
    // calculates middle value of all students
    middle = (numStudents - 1) / 2;
    
    // calculates median if data set contains odd number of values
    if ((numStudents % 2) == 1)
        medValue = *(arr + middle);
    
    // calculates median if data set contains even number of values
    else
        medValue = (*(arr + middle) + *(arr + (middle + 1))) / 2.0;
    
    return medValue;
}


// function determines which value occurs most often
int mode(int *arr, int numStudents)
{
    // declare and initialize variables
    int count = 0;
    int maxValue = 0;
    int mode = -1;
    
    // for loop moves across entire array
    for (int i = 0; i < numStudents; i++)
    {
        // for loop moves across remaining array
        for (int j = i + 1; j < numStudents; j++)
        {
            // determines if two elements have the same value
            if (*(arr + i) == *(arr + j))
                count++;
        }
        
        // sets mode to the value that appears most often in array
        if (maxValue < count)
        {
            mode = *(arr + i);
            maxValue = count;
        }
    }
    
    return mode;
}

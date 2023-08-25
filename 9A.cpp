//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 9A
//        Date: 4/28/2023
// Description: Program uses singly linked list, and the user can add, delete, display, and search values within
//              the list. Program will determine if value already exists and will keep all numbers in ascending order
//************************************************************************************************************

#include <iostream>
using namespace std;

// declare structure
struct entry
{
    int number;
    entry *next;
};

// function prototypes
bool checkDuplicate(entry*, int);
void addNode(entry* &head);
void deleteNode(entry* &head);
void displayNodes(entry*);
void searchNode(entry*);
void sortList(entry*);

int main()
{
    // declare and initialize variables
    int option = 0;

    // create empty list
    entry *head = nullptr;

    // asks for user input
    cout << "(1 - add number, 2 - delete number, 3 - search number, 4 - display numbers, 5 - exit)" << endl;
    cout << "Choose an option: ";
    cin >> option;
    cout << endl;

    // keeps looping unless user enters 5
    while (option != 5)
    {
        // choices that user has for program
        switch(option)
        {
            case 1:
                addNode(head);
                break;

            case 2:
                deleteNode(head);
                break;

            case 3:
                searchNode(head);
                break;

            case 4:
                displayNodes(head);
                break;

            default:
                cout << "Invalid input. Try again." << endl;
                break;
        }

        cout << "(1 - add number, 2 - delete number, 3 - search number, 4 - display numbers, 5 - exit)" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;
    }

    cout << "Program ending..." << endl;
}


// function checks if any nodes has a duplicate value as user input.
// function will return true if a duplicate value is found, or else, returns false.
bool checkDuplicate(entry *head, int value)
{
    // declare and initialize variable
    bool duplicate = false;

    // curr pointer gets assigned the head value
    entry *curr = head;

    // keeps looping as long as curr pointer does not reach null
    while (curr != NULL)
    {
        // returns true if curr pointer matches user input
        if (curr->number == value)
        {
            duplicate = true;
            return duplicate;
        }
        
        // assigns curr pointer to next node
        curr = curr->next;
    }

    // returns false if curr pointer does not match with user input
    return duplicate;
}


// function allows user to add value/create new node into the list.
// function will make new value stay in ascending order and will call checkDuplicate() 
// to see if the user can create a new node.
void addNode(entry *&head)
{
    // declare and initialize variable
    int userInput = 0;

    // creates pointers of entry type for curr, prev, and newNode 
    entry *curr;
    entry *prev;
    entry *newNode;

    // asks for user input
    cout << "Enter value you want to add (positive numbers only): ";
    cin >> userInput;

    // keeps looping until user input is positive value
    while (userInput < 0)
    {
        cout << "\nInvalid input. Enter value you want to add (positive numbers only): ";
        cin >> userInput;
    }

    // statement checks if list has a duplicate value
    if (checkDuplicate(head, userInput))
        cout << "Duplicate value found. Unable to add to list." << endl;

    // statement does not contain duplicate value
    else
    {
        // allocate, store, and point new data of newNode to null  
        newNode = new entry;
        newNode->number = userInput;
        newNode->next = nullptr;

        // makes newNode the first value of list if program finds that there are no other nodes
        if (head == nullptr)
            head = newNode; 

        else
        {
            // moves old curr value to null
            prev = NULL;
            curr = head;

            // keeps looping if curr does not equal null AND curr value is smaller than user Input
            while (curr != NULL && curr->number < userInput)
            {
                // moves old curr value to null and points curr to next node
                prev = NULL;
                curr = curr->next;
            }

            // statement checks to see if user input should be inserted as head
            if (prev == NULL)
            {
                newNode->next = head;
                head = newNode;
            }

            // statement adds new node at the end of list or at the found node, then assigns prev to new number
            else
            {
                newNode->next = curr;
                prev->next = newNode;
            }
        }

    }

    cout << endl;
}


// function finds a number that user inputs and deletes it from list.
// if number is not found, the value cannot be deleted
void deleteNode(entry *&head)
{
    int userInput;
    entry *curr;
    entry *prev;

    // statement sees if list has no nodes
    if (head == nullptr)
        cout << "List is empty. Cannot delete any values." << endl;
    
    // statement knows that there are nodes in the list
    else
    {
        // asks for user input
        cout << "Enter value you want to delete: ";
        cin >> userInput;
        curr = head;
        prev = NULL;

        // keeps looping unless curr pointer reaches end of list AND curr pointer matches user input
        while (curr != NULL && curr->number != userInput)
        {
            prev = curr;
            curr = curr->next;
        }

        // statement cannot find node after traversing through list
        if (curr == NULL)
            cout << "Number is not found in list." << endl;

        // statement shows that prev pointer is the only number in list (head pointer) 
        else if (prev == NULL)
        {
            head = head->next;
            delete curr;
        }

        // statement shows that user input is found somewhere on the list
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }

    cout << endl;
}


// function searches for value input by user to see if the node exists/does not exist in list
void searchNode(entry *head)
{
    // declare and initialize variable
    int userInput = 0;

    // create pointer curr with entry type
    entry *curr;

    // ask for user input
    cout << "Enter number you want searched: ";
    cin >> userInput;

    // assigns curr pointer to first number of list
    curr = head;

    // keeps looping as long as curr pointer does not reach an empty pointer AND curr pointer value is not equal to user input
    while (curr != nullptr && curr->number != userInput)
        curr = curr->next;

    // statement shows that user input is found in list
    if (curr != NULL)
        cout << "Number is found in list." << endl;

    // statement that user input is not found in list
    else
        cout << "Number is not found in list." << endl;
    
    cout << endl;
}


// function displays all nodes in a list in ascending order
void displayNodes(entry *head)
{
    // assign curr pointer to head (first number in list)
    entry *curr = head;

    // statement determines if list is empty
    if (head == nullptr)
        cout << "Empty list." << endl;

    // function call to sort list in ascending order
    sortList(head);

    // keeps looping and displaying list values until curr pointer reaches null
    while (curr != NULL)
    {
        cout << curr->number << " ";
        curr = curr->next;
    }

    cout << endl << endl;
}


// function sorts nodes in ascending order if there are nodes in a list using bubble sort
void sortList(entry *head)
{
    // declare and initialize variables
    int random = 0;

    // create pointers curr and prev, and assign them to values
    entry *prev = head;
    entry *curr = NULL;

    // keeps looping until prev pointer reaches end of list
    while (prev != NULL)
    {
        // assigns curr pointer to value after prev pointer
        curr = prev->next;

        // keeps looping as long as curr pointer does not reach end of list   
        while (curr != NULL)
        {
            // if the curr pointer value is smaller than the prev pointer value, values switch
            if (curr->number < prev->number)
            {
                random = prev->number;
                prev->number = curr->number;
                curr->number = random;
            }

            // curr pointer moves to next node
            curr = curr->next;
        }

        // prev pointer moves to next node
        prev = prev->next;
    }
}
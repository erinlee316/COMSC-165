//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 8A
//        Date: 4/22/2023
// Description: Program uses structure variable to store item, quantity, wholesale cost, and retail cost into file. User has menu options to edit records in file.
//************************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// global variable
const int SIZE = 80;

// define structure
struct Inventory
{
    char name[SIZE];
    int quantity;
    double wholesale;
    double retail;
};

// function prototypes
int displayMenu();
void initialRead();
void addRecord();
void displayRecord();
void changeRecord();
void displayAll();
void report();
void getItem(Inventory&);
void displayItem(const Inventory&);

int main()
{
    // declare and initialize variable
    int option;
    
    // function call
    initialRead();
    option = displayMenu();
    
    // keeps looping until user enters 6
    while (option != 6)
    {
        // switch offers options that user can choose
        switch (option)
        {
            case 1:
                displayAll();
                cout << endl;
                break;
                
            case 2:
                addRecord();
                cout << endl;
                break;
                
            case 3:
                changeRecord();
                cout << endl;
                break;
                
            case 4:
                displayRecord();
                cout << endl;
                break;
                
            case 5:
                report();
                cout << endl;
                break;
                
            default:
                cout << "Invalid input. Try again" << endl;
                break;
        }
        option = displayMenu();
    }
    
    cout << "Program over" << endl;

    return 0;
}


// function displays menu that user can choose from
int displayMenu()
{
    // declare and initialize variable
    int option = 0;
    
    cout << "Choose an option:" << endl;
    cout << "(1 - display ALL records, 2 - add new records, 3 - change any records," << endl;
    cout << "4 - display any records, 5 - prepare report, 6 - exit program)" << endl;
    cin >> option;
    cout << endl;
    
    return option;
}


// function reads data from file and writes it into binary file
void initialRead()
{
    Inventory temp;
    ifstream readFile;
    ofstream writeBinary;
    
    readFile.open("data.txt");
    writeBinary.open("inventory.dat", ios::out | ios::binary);
    
    // display if files cannot open
    if (!readFile && !writeBinary)
    {
        cout << "Cannot open files" << endl;
        exit(EXIT_FAILURE);
    }
    
    // files open
    else
    {
        // get information from file and insert it into struct variable
        readFile >> temp.name;
        
        // keeps loopings until end of file is reached
        while (!readFile.eof())
        {
            readFile >> temp.quantity
                     >> temp.wholesale
                     >> temp.retail;
            
            // turns struct variable into char variable and writes to binary file
            writeBinary.write(reinterpret_cast<char*>(&temp), sizeof(temp));
            readFile >> temp.name;
        }
        
        // close files after using
        readFile.close();
        writeBinary.close();
    }
}


// function displays entire contents in file
void displayAll()
{
    // declare variables
    Inventory temp;
    ifstream readFile("inventory.dat", ios::binary);
    
    // display if file cannot open
    if (!readFile)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    // file can open
    else
    {
        readFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));

        // keep looping until end of file is reached
        while (!readFile.eof())
        {
            displayItem(temp);
            readFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        }
        
        // close file after using
        readFile.close();
    }
}


// function adds an item into record
void addRecord()
{
    // declare and initialize variable
    Inventory temp;

    // function call
    getItem(temp);
    
    ofstream writeBinary("inventory.dat", ios::app | ios::binary);
    
    // display when file cannot open
    if (!writeBinary)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    else
        writeBinary.write(reinterpret_cast<char*>(&temp), sizeof(Inventory));
}


// function replaces one item from file with another item, and user must input its name, quantity, wholesale price, and retail price
void changeRecord()
{
    // declare and initialize variables
    Inventory temp;
    Inventory newItem;
    long where;
    char oldItem[SIZE];

    cout << "Enter items you want to replace: ";
    cin >> oldItem;
    getItem(newItem);
    
    fstream readWrite("inventory.dat", ios::in | ios::out | ios::binary);
    
    // display when file cannot open
    if (!readWrite)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    // file opens
    else
    {
        readWrite.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        
        // keeps looping until end of file is reached
        while (!readWrite.eof())
        {
            // compares name from struct variable to user input
            if (strcmp(temp.name, oldItem) == 0)
            {
                cout << "Item found: " << temp.name << endl;
                break;
            }
            readWrite.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        }
    }
    
    readWrite.clear();
    
    where = readWrite.tellg();
    readWrite.seekp(where-sizeof(Inventory), ios::beg);
    readWrite.write(reinterpret_cast<char*>(&newItem), sizeof(Inventory));
    readWrite.close();
}


// function displays information about one item
void displayRecord()
{
    // declare and initialize variables
    Inventory temp;
    char display[SIZE];
    
    cout << "Enter record name you want to view: ";
    cin >> display;
    
    ifstream readFile("inventory.dat", ios::binary);
    
    // display when file cannot open
    if (!readFile)
    {
        cout << "Cannot open file" << endl;
    }
    
    // file opens
    else
    {
        readFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        while (!readFile.eof())
        {
            // compares to see if the characters match
            if (strcmp(temp.name, display) == 0)
                
            {
                // displays contents of specific item from struct variable
                displayItem(temp);
                break;
            }
             
            readFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
        }
    
        // display if end of file reached and no match
        if (readFile.eof())
            cout << "Item not found" << endl;
    }
    // close file after using
    readFile.close();
}


// function displays information for specific item
void displayItem(const Inventory& item)
{
    cout << "Item name: " << item.name << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Wholesale cost: $" << item.wholesale << endl;
    cout << "Retail cost: $" << item.retail << endl;
    cout << endl;
}


// function gets information for new item
void getItem(Inventory& newItem)
{
    cout << "Enter new item name: ";
    cin >> newItem.name;

    cout << "Enter new item quantity: ";
    cin >> newItem.quantity;
    while (newItem.quantity < 1)
        {
            cout << "Invalid input. Try again (must be greater than 0): ";
            cin >> newItem.quantity;
        }

    cout << "Enter new item wholesale price: $";
    cin >> newItem.wholesale;
        while (newItem.wholesale < 1)
        {
            cout << "Invalid input. Try again (must be greater than 0): $";
            cin >> newItem.wholesale;
        }

    cout << "Enter new item retail price: $";
    cin >> newItem.retail;
        while (newItem.retail < 1)
        {
            cout << "Invalid input. Try again (must be greater than 0): $";
            cin >> newItem.retail;
        }
}


// function displays report of total items, quantity, retail price, and wholesale price of all items
void report()
{
    // declare and initialize variables
    Inventory temp;
    double totalQuantity = 0.0;
    double totalWholesale = 0.0;
    double totalRetail = 0.0;
    
    ifstream readFile("inventory.dat", ios::binary);
    
    // display when file cannot open
    if (!readFile)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    // adds total quantity, retail, and wholesale of all items
    else
    {
        while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Inventory)))
        {
            totalQuantity += temp.quantity;
            totalRetail += temp.retail;
            totalWholesale += temp.wholesale;
        }
        readFile.close();
    }
    
    // display results
    cout << "REPORT" << endl;
    cout << "Total quantity of items: " << totalQuantity << endl;
    cout << "Total retail amount: $" << totalRetail << endl;
    cout << "Total wholesale amount: $" << totalWholesale << endl;
}

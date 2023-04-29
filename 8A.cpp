//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 8A
//        Date: 4/21/2023
// Description: Program reads data from one file, modifying the data and writing it into a second file. The second file will decrypt the encrypted file and write the data into another file. 
//************************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

// function prototypes
void originalFile();
void encryptFile();
void decryptFile();

int main()
{
    // function call
    originalFile();
    encryptFile();
    decryptFile();
    
    return 0;
}


// function displays contents of original file
void originalFile()
{
    // declare and initialize data
    string data;
    ifstream original("apple.txt");

    // display if file cannot open
    if (!original)
    {   
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    // display if file can open
    else
    {
        cout << "Original data: ";

        // keeps looping until end of file is reached
        while (!original.eof())
        {
            getline(original, data);
            cout << data;
        }

        cout << endl;
    }

}


// function will encrypt data into a file and modify the data into a code
void encryptFile()
{
    // declare and initialize variable
    char ch;
        
    // open files for reading and writing
    fstream original("apple.txt", ios::in);
    ofstream encryption("banana.txt");
    
    // display if cannot open file
    if (!original)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    // display if can open file
    else
    { 
        cout << "Data will now encrypt" << endl;
        cout << "Encrypted data: ";

        // loop keeps going until end of file reaches
        while (!original.eof())
        {
            // adds 10 to ASCII code from readFile and prints it into writeFile
            original.get(ch);
            ch = ch + 10;
            encryption << ch;
            cout << ch;
        }
        
        // close files after using
        original.close();
        encryption.close();
        
        cout << endl;
    }
}


// function will decrypt data into a new file and remodify code back to original data
void decryptFile()
{
    // declare and initialize variable
    char ch;
        
    // open files for reading and writing
    fstream encryption("banana.txt", ios::in);
    ofstream decryption("carrot.txt");
    
    // display if file cannot open
    if (!encryption)
    {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    } 
    
    // display if file can open
    else
    {
        cout << "Data will now decrypt" << endl;
        cout << "Decrypted data: ";

        // loop keeps going until end of file reaches
        while (!encryption.eof())
        {
            // subtracts 10 to ASCII code from readFile and prints it into writeFile
            encryption.get(ch);
            ch = ch - 10;
            decryption << ch;
            cout << ch;
        }
        
        // close files after using
        encryption.close();
        decryption.close();
        
        cout << endl;
    }
}

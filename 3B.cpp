//*******************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 3B
//        Date: 2/17/2023
// Description: Program allows two people to play a tic tac toe game. Users will enter two digits to select a location on the game board. Winner is determined when player one or player two mark three squares with (X) or (O) in a row.
//*******************************************************************************************************

#include <iostream>
using namespace std;

// declare and initialize constant variables
const int ROWS = 3;
const int COLS = 3;

// function prototypes
void displayBoard(char [][COLS]);
void playerTurn(char [][COLS], char);
void displayWinner(char [][COLS]);
bool gameOver(char [][COLS]);
bool playerWins(char[][COLS], char);
bool playerCanWin(char [][COLS], char);


int main()
{
    // array for the game board
    char gameboard[ROWS][COLS] = { '*', '*', '*',
                                   '*', '*', '*',
                                   '*', '*', '*'};
    
    do
    {
        // display game board
        displayBoard(gameboard);
        
        // player one's turn
        playerTurn(gameboard, 'X');
        
        // display game board
        displayBoard(gameboard);

        // statement determines if it is player two's turn
        if (!gameOver(gameboard))
            playerTurn(gameboard, 'O');
    }
    
    // loop continues if game has not ended
    while (!gameOver(gameboard));
    
    // display game board
    displayBoard(gameboard);
    
    // display game winner
    displayWinner(gameboard);
    
    return 0;
}

// function displays the contents on the game board
void displayBoard(char board[][COLS])
{
    // displays columns for game board
    cout << "       Columns" << endl;
    cout << "       1 2 3" << endl;
    
    // for loop displays rows for game board
    for (int row = 0; row < ROWS; row++)
    {
        // displays row label
        cout << "Row " << (row + 1) << ": ";
        
        // displays row contents
        for (int col = 0; col < COLS; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// function allows player one and two to choose a location on game board
void playerTurn(char board[][COLS], char symbol)
{
    // bool becomes true if board spot is available
    bool isAvailable = false;
    
    // declare variables
    int row;
    int col;
    
    // prompt player to enter a location on board
    cout << "Player " << symbol << "'s turn." << endl;
    cout << "Enter a row and column to place an " << symbol << endl;
    
    // get and validate the location
    while (!isAvailable)
    {
        // user inputs row
        cout << "Row: ";
        cin >> row;
        
        // asks for user input again if row does not exist
        while (row < 1 || row > ROWS)
        {
            cout << "Invalid Row" << endl;
            cout << "Row: ";
            cin >> row;
        }
        
        // user inputs column
        cout << "Column: ";
        cin >> col;
        
        // asks for user input again if column does not exist
        while (col < 1 || col > COLS)
        {
            cout << "Invalid Column" << endl;
            cout << "Column: ";
            cin >> col;
        }
        
        // statement determines whether the selected location is available
        if (board[row - 1][col - 1] == '*')
            isAvailable = true;
        
        else
        {
            cout << "That location is not available. Select another location." << endl;
        }
    }
    
    // the player's symbol gets marked at the selected location on board
    board[row - 1][col - 1] = symbol;
}

// function returns true if either player won, or the game ended in a tie
bool gameOver(char board[][COLS])
{
    // declare variable
    bool status;
    
    // game ends if either player won
    if (playerWins(board, 'X') || playerWins(board, 'O'))
        status = true;
    
    // game continues if either player can still win
    else if (playerCanWin(board, 'X') || playerCanWin(board, 'O'))
        status = false;
    
    // game ends if players tie
    else
        status = true;
    
    return status;
}

// function returns true if either player won, and it accepts symbol (X) and (O) as arguments.
bool playerWins(char board[][COLS], char symbol)
{
    // bool status initialized to false
    bool status = false;
    
    // check the first row
    if ((board[0][0] == symbol) && (board[0][1] == symbol) && (board[0][2] == symbol))
        status = true;
    
    // check the second row
    if ((board[1][0] == symbol) && (board[1][1] == symbol) && (board[1][2] == symbol))
        status = true;
    
    // check the third row
    if ((board[2][0] == symbol) && (board[2][1] == symbol) && (board[2][2] == symbol))
        status = true;
    
    // check the first column
    if ((board[0][0] == symbol) && (board[1][0] == symbol) && (board[2][0] == symbol))
        status = true;

    // check the second column
    if ((board[0][1] == symbol) && (board[1][1] == symbol) && (board[2][1] == symbol))
        status = true;
    
    // check the third column
    if ((board[0][2] == symbol) && (board[1][2] == symbol) && (board[2][2] == symbol))
        status = true;
    
    //check diagonal
    if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
        status = true;
    
    // if status is still false, the player has yet to win
    return status;
}
    
// function returns true if either player can still win
bool playerCanWin(char board[][COLS], char symbol)
{
    // bool status initializes as false
    bool status = false;
    
    // check the first row for a possibility
    if ((board[0][0] == symbol || board[0][0] == '*') &&
        (board[0][1] == symbol || board[0][1] == '*') &&
        (board[0][2] == symbol || board[0][2] == '*'))
        status = true;
    
    // check the second row for a possibility
    if ((board[1][0] == symbol || board[1][0] == '*') &&
        (board[1][1] == symbol || board[1][1] == '*') &&
        (board[1][2] == symbol || board[1][2] == '*'))
        status = true;
    
    // check the third row for a possibility
    if ((board[2][0] == symbol || board[2][0] == '*') &&
        (board[2][1] == symbol || board[2][1] == '*') &&
        (board[2][2] == symbol || board[2][2] == '*'))
        status = true;
    
    // check the first column for a possibility
    if ((board[0][0] == symbol || board[0][0] == '*') &&
        (board[1][0] == symbol || board[1][0] == '*') &&
        (board[2][0] == symbol || board[2][0] == '*'))
        status = true;
    
    // check the second column for a possibility
    if ((board[0][1] == symbol || board[0][1] == '*') &&
        (board[1][1] == symbol || board[1][1] == '*') &&
        (board[2][1] == symbol || board[2][1] == '*'))
        status = true;
    
    // check the third column for a possibility
    if ((board[0][2] == symbol || board[0][2] == '*') &&
        (board[1][2] == symbol || board[1][2] == '*') &&
        (board[2][2] == symbol || board[2][2] == '*'))
        status = true;
    
    // check the diagonal for a possibility
    if ((board[0][0] == symbol || board[0][0] == '*') &&
        (board[1][1] == symbol || board[1][1] == '*') &&
        (board[2][2] == symbol || board[2][2] == '*'))
        status = true;
    
    // if status is still false, the player cannot win
    return status;
}
    
// function displays the game winner
void displayWinner(char board[][COLS])
{
    if (playerWins(board, 'X'))
        cout << "Player 1 (X) wins!" << endl;
    else if (playerWins(board, 'O'))
        cout << "Player 2 (O) wins!" << endl;
    else
        cout << "Player 1 and player 2 tie. Game Over" << endl;
}

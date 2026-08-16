#include <iostream>
#include <vector>

#include "SudokuBoard.h"

using namespace std;


SudokuBoard::SudokuBoard() {

    // Reserving all the Board slots in the 2D vector array
    board.resize(9);
    for(int i = 0; i < 9; i++) {
        board[i].resize(9);
    }
}

SudokuBoard& SudokuBoard::instance() {
    static SudokuBoard instance;
    return instance;
}



bool SudokuBoard::posCheck(int row, int col) 
{
    int val = this->board.at(row).at(col);
    // Check no matching value in the same Column
    for(int i = 0; i < 9; i++)
    {
        try {
                if( i != row &&
                (this->board).at(i).at(col) == val ) {
                    return false;
                }
            }
        catch(...) { /* Just accessing out of boundry, safe skip here */ }
            
        try {
                if( i != col && 
                    (this->board).at(row).at(i) == val ) {
                    return false;
                }  
            }
        catch(...) { /* Just accessing out of boundry, safe skip here */ }

        try {
                int boxRow = 3 * (row / 3) + (i / 3);
                int boxCol = 3 * (col / 3) + (i % 3);

                if( (boxRow != row || boxCol != col) &&
                (this->board).at(boxRow).at(boxCol) == val ) {
                    return false;
                }  
            }
        catch(...) { /* Just accessing out of boundry, safe skip here */ }
    }

    return true;
}

int SudokuBoard::getPos(int conceptual_row, int conceptual_col) {

    return this->board.at(conceptual_row - 1).at(conceptual_col - 1);
}

bool SudokuBoard::placePos(int conceptual_row, int conceptual_col, int val) {
    
    int row = conceptual_row - 1;
    int col = conceptual_col - 1;

    // ---------------------------------------
    // These Validations must be handled by exceptions
    // ---------------------------------------
    
    // Check the validity of the entered value number
    if(val > 9 || val < 0) { cout << "Wrong Value Number" << endl; return false; }
    
    // Check the validity of the entered row number
    if(row > 8 || row < 0) { cout << "Wrong Row Number" << endl; return false; }
    
    // Check the validity of the entered column cumer
    if(col > 8 || col < 0) { cout << "Wrong Column Number" << endl; return false; }
    
    // Check if putting a value that already exists in the choosed position
    if(this->board.at(row).at(col) == val) { return true; }

    // Attempting to change the value in a slot
    int temp = this->board.at(row).at(col);
    this->board.at(row).at(col) = val;
    
    // Check the vality of the change
    if( !posCheck(row, col) ) { 
        cout << "Can't Place this number here" << endl; 
        this->board.at(row).at(col) = temp;

        return false;
    }
    
    return true;
}


bool SudokuBoard::clearPos(int conceptual_row, int conceptual_col) {

    int row = conceptual_row - 1;
    int col = conceptual_col - 1;

    // ---------------------------------------
    // These Validations must be handled by exceptions
    // ---------------------------------------

    // Check the validity of the entered row number
    if(row > 9 || row < 0) { cout << "Wrong Row Number" << endl; return false; }
    
    // Check the validity of the entered column cumer
    if(col > 9 || col < 0) { cout << "Wrong Column Number" << endl; return false; }
    
    this->board.at(row).at(col) = 0;
    return true;
}




void SudokuBoard::demoBoard() {
    
    
    // ---------------------------------------
    // Hard coding the demo construction of the board.
    // ---------------------------------------
    
    
    board.at(0).at(0) = 5;
    board.at(0).at(1) = 3;
    board.at(0).at(4) = 7;

    board.at(1).at(0) = 6;
    board.at(1).at(3) = 1;
    board.at(1).at(4) = 9;
    board.at(1).at(5) = 5;

    board.at(2).at(1) = 9;
    board.at(2).at(2) = 8;
    board.at(2).at(7) = 6;

    board.at(3).at(0) = 8;
    board.at(3).at(4) = 6;
    board.at(3).at(8) = 3;

    board.at(4).at(0) = 4;
    board.at(4).at(3) = 8;
    board.at(4).at(5) = 3;
    board.at(4).at(8) = 1;

    board.at(5).at(0) = 7;
    board.at(5).at(4) = 2;
    board.at(5).at(8) = 6;

    board.at(6).at(1) = 6;
    board.at(6).at(6) = 2;
    board.at(6).at(7) = 8;

    board.at(7).at(3) = 4;
    board.at(7).at(4) = 1;
    board.at(7).at(5) = 9;
    board.at(7).at(8) = 5;

    board.at(8).at(4) = 8;
    board.at(8).at(7) = 7;
    board.at(8).at(8) = 9;
}
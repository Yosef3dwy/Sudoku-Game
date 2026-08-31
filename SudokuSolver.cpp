#include <iostream>
#include "SudokuBoard.h"
#include "SudokuSolver.h"

using namespace std;

SudokuSolver::SudokuSolver(SudokuBoard& SuBoard)
{
    this->SuBoard = &SuBoard;
}


SudokuSolver &SudokuSolver::instance(SudokuBoard& SuBoard)
{
    static SudokuSolver instance(SuBoard);
    return instance;
}

bool SudokuSolver::backtrack(int row_I, int col_I)
{
    int emptyCount = (this->SuBoard)->getEmptyCount();

    // Check if the board has been completely filled
    if(emptyCount == 0)
    {
        return true;
    }

    int col_loop = col_I;
    for(int row = row_I; row <= 9; row++)
    {
        for(int col = col_loop; col <= 9; col++)
        {

            // Check if the current postition is empty before continue Descending the Tree
            if((this->SuBoard)->getPos(row, col) == 0) 
            {

                // Iterate and try all numbers
                for(int val = 1; val <= 9; val++)
                {

                    // Do
                    if((this->SuBoard)->placePos(row, col, val) == true)
                    {
                    
                    // Recurce
                        if(this->backtrack(row, col) == true)
                        {
                            return true; 
                            // Once a solution is found, return all the way up the tree to finish up the algorithm
                        }
                    
                    // Undo
                        (this->SuBoard)->clearPos(row, col);
                    }
                }

                // If all numbers combinations in this postion wasn't able to solve the board
                // Then the board is UNSOLVABLE
                return false;
            }
        }

        col_loop = 1;
    }


    return false;
}

void SudokuSolver::boardSolver()
{
    this->backtrack(1, 1);
}
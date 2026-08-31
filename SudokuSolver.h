#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include "SudokuBoard.h"

class SudokuSolver {

private:
    SudokuBoard* SuBoard;

    // The Backtrack recursive function algorithm
    bool backtrack(int row_I, int col_I);

public:
    SudokuSolver(SudokuBoard& SuBoard);
    static SudokuSolver& instance(SudokuBoard& SuBoard);

    // Auxilary function for starting the Board Solver algorithm
    void boardSolver();
};

#endif
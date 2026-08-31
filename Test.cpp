#include <iostream>
#include "Board/SudokuBoard.h"
#include "Solver/SudokuSolver.h"


using namespace std;


int main() {
    cout << endl;

    SudokuBoard& SuBoard = SudokuBoard::instance();
    SuBoard.demoBoard();
    
    // ---------------------------------------
    // Placing Test
    // ---------------------------------------
    
    // Test Normal Placing
    cout << ((SuBoard.placePos(1, 3, 4))? "Placed Successful": "Failed to Place")  << endl << endl;
    
    // Clear Test
    cout << ((SuBoard.clearPos(3, 8))? "Placed Successful": "Failed to Place")  << endl << endl;
    
    // Test Invalid Placing
        // Rows and Columns Check
        cout << ((SuBoard.placePos(1, 6, 4))? "Placed Successful": "Failed to Place")  << endl << endl;
        // Same Block Check "To be Handled"
        cout << ((SuBoard.placePos(2, 2, 4))? "Placed Successful": "Failed to Place")  << endl << endl;
    
    // Test Invalid Row & Column & Value
    cout << ((SuBoard.placePos(10, 2, 4))? "Placed Successful": "Failed to Place")  << endl << endl;
    cout << ((SuBoard.placePos(1, 32, 4))? "Placed Successful": "Failed to Place")  << endl << endl;
    cout << ((SuBoard.placePos(1, 2, 14))? "Placed Successful": "Failed to Place")  << endl << endl;
    
    // ---------------------------------------
    // Solving Test
    // ---------------------------------------

    SudokuSolver& SuSolver = SudokuSolver::instance(SuBoard);
    SuSolver.boardSolver();

    // ---------------------------------------
    // Display Board
    // ---------------------------------------
    cout << endl << endl;
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++) {

            try {
        
                if(SuBoard.getPos(i, j)) {
                    cout << SuBoard.getPos(i, j) << " ";
                } else {
                    cout << "_ ";
                }
    
            } catch (...) { /* Just accessing out of boundry, safe skip here */ }

            if(j != 0 && j % 3 == 0) { cout << " "; }
        }

        cout << endl;

        if(i != 0 && i % 3 == 0) { cout << endl; } 
    }
    cout << endl << endl;

    return 0;
}
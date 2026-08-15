#include <iostream>
#include <vector>

class SudokuBoard {

private:
    std::vector<std::vector<int>> board;

    
    // Validity check helper method 
    bool posCheck(int row, int col);
    
public:
    SudokuBoard();
    static SudokuBoard& instance();

    // Return the number in a position on the Board
    int getPos(int conceptual_row, int conceptual_col);

    // Change the value the exists in a position on the Board
    bool placePos(int conceptual_row, int conceptual_col, int val);

    // Clear a position
    bool clearPos(int conceptual_row, int conceptual_col);

    // Hard coded mid level construction of the board (Testing)
    void demoBoard();
};
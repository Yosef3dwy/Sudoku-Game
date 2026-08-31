CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -IBoard -ISolver

TARGET = SudokuTest.exe

$(TARGET): Board/SudokuBoard.cpp Solver/SudokuSolver.cpp Test.cpp
	$(CXX) $(CXXFLAGS) Board/SudokuBoard.cpp Solver/SudokuSolver.cpp Test.cpp -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q $(TARGET) 2>nul

all: $(TARGET)
	.\$(TARGET)
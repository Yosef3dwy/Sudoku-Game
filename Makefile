CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = SudokuTest.exe

$(TARGET): SudokuBoard.cpp SudokuSolver.cpp Test.cpp
	$(CXX) $(CXXFLAGS) SudokuBoard.cpp SudokuSolver.cpp Test.cpp -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q $(TARGET) 2>nul

all: $(TARGET)
	.\$(TARGET)
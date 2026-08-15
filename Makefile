CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = SudokuTest.exe

$(TARGET): SudokuBoard.cpp Test.cpp
	$(CXX) $(CXXFLAGS) SudokuBoard.cpp Test.cpp -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q $(TARGET) 2>nul

all: $(TARGET)
	.\$(TARGET)
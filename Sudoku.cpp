#include <iostream>
using namespace std;

const int N = 9;
int grid[N][N];

// Function to check if a given value can be placed in the current cell
bool isSafe(int row, int col, int num) {
    // Check if the same value exists in the current row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // Check if the same value exists in the current column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // Check if the same value exists in the current 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    // If the value can be placed in the current cell, return true
    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku() {
    int row, col;
    bool isEmpty = false;
    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    // If there are no empty cells, the puzzle is solved
    if (!isEmpty) {
        return true;
    }
    // Try all values from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            // If the value is safe to place, assign it to the current cell
            grid[row][col] = num;
            // Recursively solve the remaining puzzle
            if (solveSudoku()) {
                return true;
            }
            // If the puzzle cannot be solved with the current value, backtrack and try the next value
            grid[row][col] = 0;
        }
    }
    // If no value can be placed in the current cell, backtrack and try a different value in the previous cell
    return false;
}

// Function to print the Sudoku grid
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    // Input the Sudoku grid
    cout << "Enter the Sudoku grid (0 for empty cells):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    // Solve the Sudoku puzzle
    if (solveSudoku()) {
        cout << "Solved Sudoku:\n";
        printGrid();
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}

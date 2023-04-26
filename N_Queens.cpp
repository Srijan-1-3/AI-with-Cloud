#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<int>& solution) {
    int n = solution.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (solution[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<int>& solution, int row, int col) {
    int n = solution.size();
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (solution[i] == col) {
            return false;
        }
    }
    // Check if there is a queen in the diagonal (left-top to right-bottom)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (solution[i] == j) {
            return false;
        }
    }
    // Check if there is a queen in the diagonal (right-top to left-bottom)
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (solution[i] == j) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& solution, int row, int& count) {
    int n = solution.size();
    if (row == n) {
        printSolution(solution);
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(solution, row, col)) {
            solution[row] = col;
            solveNQueens(solution, row + 1, count);
            solution[row] = -1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> solution(n, -1);
    int count = 0;
    solveNQueens(solution, 0, count);
    cout << "Total solutions: " << count << endl;
    return 0;
}

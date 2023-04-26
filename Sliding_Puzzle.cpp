#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_puzzle(int puzzle[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i][j] == 0) {
                cout << "  ";
            } else {
                cout << puzzle[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool check_win(int puzzle[3][3]) {
    int count = 0;
    int check[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            check[count] = puzzle[i][j];
            count++;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (check[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void move(int puzzle[3][3], char direction) {
    int row, col, temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i][j] == 0) {
                row = i;
                col = j;
            }
        }
    }
    switch (direction) {
        case 'u':
            if (row > 0) {
                temp = puzzle[row][col];
                puzzle[row][col] = puzzle[row-1][col];
                puzzle[row-1][col] = temp;
            }
            break;
        case 'd':
            if (row < 2) {
                temp = puzzle[row][col];
                puzzle[row][col] = puzzle[row+1][col];
                puzzle[row+1][col] = temp;
            }
            break;
        case 'l':
            if (col > 0) {
                temp = puzzle[row][col];
                puzzle[row][col] = puzzle[row][col-1];
                puzzle[row][col-1] = temp;
            }
            break;
        case 'r':
            if (col < 2) {
                temp = puzzle[row][col];
                puzzle[row][col] = puzzle[row][col+1];
                puzzle[row][col+1] = temp;
            }
            break;
    }
}

int main() {
    int puzzle[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                move(puzzle, 'u');
                break;
            case 1:
                move(puzzle, 'd');
                break;
            case 2:
                move(puzzle, 'l');
                break;
            case 3:
                move(puzzle, 'r');
                break;
        }
    }
    char direction;
    while (!check_win(puzzle)) {
        print_puzzle(puzzle);
        cout << "Enter direction (u/d/l/r): ";
        cin >> direction;
        move(puzzle, direction);
    }
    print_puzzle(puzzle);
    cout << "You win!" << endl;
    return 0;
}


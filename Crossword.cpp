#include <iostream>
#include <cstring>
using namespace std;

#define ROWS 10
#define COLS 10

char puzzle[ROWS][COLS] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

bool is_valid_location(int row, int col, int len, int dir) {
    if (dir == 0) {
        if (row + len > ROWS) {
            return false;
        }
        for (int i = row; i < row + len; i++) {
            if (puzzle[i][col] != '*') {
                return false;
            }
        }
    } else {
        if (col + len > COLS) {
            return false;
        }
        for (int j = col; j < col + len; j++) {
            if (puzzle[row][j] != '*') {
                return false;
            }
        }
    }
    return true;
}

void set_word(int row, int col, int len, int dir, char word[]) {
    if (dir == 0) {
        for (int i = row; i < row + len; i++) {
            puzzle[i][col] = word[i - row];
        }
    } else {
        for (int j = col; j < col + len; j++) {
            puzzle[row][j] = word[j - col];
        }
    }
}

void print_puzzle() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

void solve_puzzle(char words[][10], int n) {
    for (int i = 0; i < n; i++) {
        int len = strlen(words[i]);
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                if (is_valid_location(j, k, len, 0)) {
                    set_word(j, k, len, 0, words[i]);
                }
                if (is_valid_location(j, k, len, 1)) {
                    set_word(j, k, len, 1, words[i]);
                }
            }
        }
    }
}

int main() {
    char words[][10] = {"hello", "world", "cpp", "crossword", "puzzle"};
    int n = 5;

    solve_puzzle(words, n);
    print_puzzle();

    return 0;
}

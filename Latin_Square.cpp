#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateLatinSquare(int n) {
    vector<vector<int>> square(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = (i + j) % n;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (square[0][i] == square[k][j]) {
                    for (int l = 0; l < n; l++) {
                        swap(square[k][l], square[i][l]);
                    }
                    break;
                }
            }
        }
    }

    return square;
}

int main() {
    int n = 5;
    vector<vector<int>> latinSquare = generateLatinSquare(n);

    cout << "Latin Square of order " << n << ":" << endl;
    for (auto row : latinSquare) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

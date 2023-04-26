#include <iostream>
using namespace std;
char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char player = 'X';
void draw_board() {
    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}
bool check_win() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}
void player_turn() {
    int row, col;
    cout << "Player " << player << ", enter row (1-3): ";
    cin >> row;
    cout << "Player " << player << ", enter column (1-3): ";
    cin >> col;
    row--;
    col--;
    if(board[row][col] == ' ') {
        board[row][col] = player;
        if(player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    } else {
        cout << "That spot is already taken, try again!" << endl;
        player_turn();
    }
}
int main() {
    draw_board();
    while(!check_win()) {
        player_turn();
        draw_board();
    }
    if(player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
    cout << "Player " << player << " wins!" << endl;
    return 0;
}

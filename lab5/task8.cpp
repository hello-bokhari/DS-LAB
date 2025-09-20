//DS LAB 5 24k0600 abbad
#include <iostream>
using namespace std;

#define SIZE 4
bool board[SIZE][SIZE];

bool isSafeFlag(int row, int col) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < SIZE; i--, j++) if (board[i][j]) return false;
    return true;
}
bool solveFlags(int row) {
    if (row >= SIZE) return true;
    for (int col = 0; col < SIZE; col++) {
        if (isSafeFlag(row, col)) {
            board[row][col] = true;
            if (solveFlags(row + 1)) return true;
            board[row][col] = false;
        }
    }
    return false;
}
int main() {
    solveFlags(0);
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << (board[i][j] ? "F " : ". ");
            if (board[i][j]) count++;
        }
        cout << endl;
    }
    cout << "Maximum Flags: " << count << endl;
    return 0;
}

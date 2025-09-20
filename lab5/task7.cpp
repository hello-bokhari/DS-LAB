//DS LAB 5 24k0600 abbad
#include <iostream>
using namespace std;

#define N 5
int maze[N][N] = {
    {1,0,1,0,1},
    {1,1,1,1,1},
    {0,1,0,1,1},
    {1,0,0,1,1},
    {1,1,1,0,1}
};
int sol[N][N] = {0};

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}
bool solveMazeUtil(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x, y)) {
        sol[x][y] = 1;
        if (solveMazeUtil(x + 1, y)) return true;
        if (solveMazeUtil(x, y + 1)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}
int main() {
    solveMazeUtil(0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << sol[i][j] << " ";
        cout << endl;
    }
    return 0;
}

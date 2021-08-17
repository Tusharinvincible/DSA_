#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector < vector < int >> & maze, int i, int j) {
    if (i >= 0 && i < maze.size() && j >= 0 && j < maze[0].size() && maze[i][j] == 1) {

        return true;

    }

    return false;
}

bool isReachable(vector < vector < int >> & maze, int i, int j) {
    if (i == (maze.size() - 1) && j == (maze[0].size() - 1) && maze[i][j] == 1) {
        return true;
    }

    if (isPossible(maze, i, j)) {
        if (isReachable(maze, i + 1, j)) {
            return true;
        } else if (isReachable(maze, i, j + 1)) {
            return true;
        }
    }

    return false;


}

int main() {
    int row, col;
    cout << "Enter the Row and Col:  ";
    cin >> row >> col;

    vector < vector < int > > maze(row, vector < int > (col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> maze[i][j];
        }
    }

    if (isReachable(maze, 0, 0)) {
        cout << "Yes it is Possible: " << endl;
    } else {
        cout << "No its not Possible:   " << endl;
    }

    return 0;
}
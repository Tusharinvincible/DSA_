#include <bits/stdc++.h>

using namespace std;
bool isPossible(int currX, int currY, vector < vector < int >> & sudoku, int i) {
    int row = sudoku.size();
    for (int j = 0; j < row; j++) {
        if (sudoku[currX][j] == i || sudoku[j][currY] == i) {
            return false;
        }
    }
    return true;
}

bool sudokuSolver(vector < vector < int >> & sudoku, int currX, int currY, int row, int col) {
    if (currX == (row - 1) && currY == row) {

        return true;

    }
    if (currY == col) {
        currY = 0;
        currX++;
    }
    if (sudoku[currX][currY] > 0) {
        sudokuSolver(sudoku, currX, currY + 1, row, col);

    } else {
        for (int i = 1; i <= row; i++) {
            if (isPossible(currX, currY, sudoku, i)) {
                sudoku[currX][currY] = i;
                if (sudokuSolver(sudoku, currX, currY + 1, row, col))
                    return true;
                sudoku[currX][currY] = 0;
            }
        }
    }

    return false;

}

int main() {

    int row;
    cin >> row;
    vector < vector < int >> sudoku(row, vector < int > (row, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            cin >> sudoku[i][j];
        }
    }
    if (sudokuSolver(sudoku, 0, 0, row, row)) {
        cout << "PRINTING SUDOKU";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                cout << sudoku[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "NOT POSSIBLE" << endl;
    }

    return 0;
}

// 3  9  6  5  7  8  4  1  2  
// 5  2  9  4  3  1  8  6  7
// 6  8  7  9  2  4  5  3  1
// 2  4  3  6  1  5  7  8  9
// 9  7  2  8  6  3  1  4  5
// 4  5  8  1  9  7  6  2  3
// 1  3  4  7  8  9  2  5  6
// 8  6  1  3  5  2  9  7  4
// 7  1  5  2  4  6  3  9  8
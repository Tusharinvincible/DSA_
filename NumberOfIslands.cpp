#include <bits/stdc++.h>

using namespace std;

bool isPossible(int i, int j, vector < vector < char >> & M, int n, int m, vector < vector < bool >> & isVisited) {
  if (i >= 0 && i < n && j >= 0 && j < m && M[i][j] == '1' && isVisited[i][j] == false) {
    return true;
  }
  return false;
}
void dfs(int i, int j, vector < vector < char >> & M, int n, int m, vector < vector < bool >> & isVisited) {
  isVisited[i][j] = true;

  if (isPossible(i - 1, j, M, n, m, isVisited)) {
    dfs(i - 1, j, M, n, m, isVisited);
  }
  if (isPossible(i - 1, j - 1, M, n, m, isVisited)) {
    dfs(i - 1, j - 1, M, n, m, isVisited);
  }
  if (isPossible(i - 1, j + 1, M, n, m, isVisited)) {
    dfs(i - 1, j + 1, M, n, m, isVisited);
  }
  if (isPossible(i, j - 1, M, n, m, isVisited)) {
    dfs(i, j - 1, M, n, m, isVisited);
  }
  if (isPossible(i, j + 1, M, n, m, isVisited)) {
    dfs(i, j + 1, M, n, m, isVisited);
  }
  if (isPossible(i + 1, j, M, n, m, isVisited)) {
    dfs(i + 1, j, M, n, m, isVisited);
  }
  if (isPossible(i + 1, j - 1, M, n, m, isVisited)) {
    dfs(i + 1, j - 1, M, n, m, isVisited);
  }
  if (isPossible(i + 1, j + 1, M, n, m, isVisited)) {
    dfs(i + 1, j + 1, M, n, m, isVisited);
  }

}
int numIslands(vector < vector < char >> & grid) {

  int n = grid.size();
  int m = grid[0].size();
  vector < vector < bool >> isVisited(n, vector < bool > (m, false));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isVisited[i][j] == false && grid[i][j] == '1') {
        dfs(i, j, grid, n, m, isVisited);
        ans++;
      }
    }

  }
  return ans;
}

int main() {

  return 0;
}
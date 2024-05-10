#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(
  vector<vector<char>>& grid, vector<vector<int>>& visited, vector<vector<int>>& dirs,
  int& n, int i, int j
) {
  visited[i][j] = 1;
  for(int d = 0; d < 4; d++) {
    int x = i+dirs[d][0], y = j+dirs[d][1];
    if(x < 0 || x > 1 || y < 0 || y > n-1 || visited[x][y]) continue;
    visited[x][y] = 1;
    if(grid[x][y] == '>') dfs(grid, visited, dirs, n, x, y+1);
    else dfs(grid, visited, dirs, n, x, y-1);
  }
  return;
}

int main() {
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    vector<vector<char>> grid(2, vector<char>(n));
    vector<vector<int>> visited(2, vector<int>(n));
    vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
    for(int i = 0; i < 2; i++) 
      for(int j = 0; j < n; j++)
        cin >> grid[i][j];
    dfs(grid, visited, dirs, n, 0, 0); 
    cout << (visited[1][n-1] ? "YES\n" : "NO\n");
  }
  return 0;
}


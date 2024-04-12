#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

void dfs(vector<vector<int>>& visited, vector<vector<char>>& grid, int i, int j) {
  if(
    i > (int)grid.size()-1 || i < 0 || j > (int)grid[0].size()-1 || j < 0 ||
    grid[i][j] != '.' || visited[i][j] != 0
  ) return;
  visited[i][j] = 1;
  for(int k = 0; k < 4; k++) {
    dfs(visited, grid, i+dirs[k][0], j+dirs[k][1]); 
  }
  return;
}

int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
  vector<vector<int>> visited(n, vector<int>(m));
  int rooms = 0;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] != '.' || visited[i][j] != 0) continue;
      dfs(visited, grid, i, j);
      rooms++;
    }
  }
  cout << rooms << '\n';
}

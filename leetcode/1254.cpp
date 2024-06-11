class Solution {
private:
  int dfs(
    vector<vector<int>>& grid, vector<vector<int>>& visited,
    vector<vector<int>>& dirs, int i, int j
  ) {
    if(i > (int)grid.size()-1 || i < 0 || j > (int)grid[0].size()-1 || j < 0) return 0;
    if(grid[i][j] != 0 || visited[i][j] != 0) return 1;
    visited[i][j] = 1;
    int x = 1;
    for(int k = 0; k < 4; k++) {
      x &= dfs(visited, grid, dirs, i+dirs[k][0], j+dirs[k][1]);
    }
    return x;
  }
public:
  int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> visited(n, vector<int>(m));
    int count = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(visited[i][j] != 0 || grid[i][j] == 1) continue;
        count += dfs(grid, visited, dirs, i, j);
      }
    }
    return count;
  }
};


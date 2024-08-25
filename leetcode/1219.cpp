class Solution {
private:
  vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  int dfs(
    vector<vector<int>>& grid, vector<vector<bool>>& visited,
    int i, int j
  ) {
    if(
      i < 0 || i > grid.size()-1 ||
      j < 0 || j > grid[0].size()-1 ||
      visited[i][j] || grid[i][j] == 0
    ) return 0;
    visited[i][j] = true;
    int m = 0;
    for(int d = 0; d < dirs.size(); d++) {
      int di = i+dirs[d][0], dj = j+dirs[d][1];
      m = max(m, dfs(grid, visited, di, dj));
    }
    visited[i][j] = false;
    return grid[i][j]+m;
  }
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(grid[i][j] == 0) continue;
        res = max(res, dfs(grid, visited, i, j));
      }
    }
    return res;
  }
};


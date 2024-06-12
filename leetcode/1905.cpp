class Solution {
private:
  int dfs(
    vector<vector<int>>& grid1, vector<vector<int>>& grid2,
    vector<vector<int>>& visited, vector<vector<int>>& dirs,
    int i, int j
  ) {
    if(
      i > (int)grid1.size()-1 || i < 0 || j > (int)grid1[0].size()-1 || j < 0 ||
      grid2[i][j] == 0 || visited[i][j] != 0
    ) return 1;
    if(grid2[i][j] != grid1[i][j]) return 0;
    visited[i][j] = 1;
    int x = 1;
    for(int k = 0; k < 4; k++)
      x &= dfs(grid1, grid2, visited, dirs, i+dirs[k][0], j+dirs[k][1]);
    return x;
  }
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size(), n = grid1[0].size();
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> visited(m, vector<int>(n));
    int count = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(visited[i][j] != 0 || grid2[i][j] == 0) continue;
        count += dfs(grid1, grid2, visited, dirs, i, j);
      }
    }
    return count;
  }
};


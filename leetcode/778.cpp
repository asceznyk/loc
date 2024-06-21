const int INF  = 4096;

class Solution {
private:
  bool dfs(
    vector<vector<int>>& grid, vector<vector<int>>& visited,
    vector<vector<int>>& dirs, int i, int j, int n, int t
  ) {
    if(
      i > n-1 || i < 0 || j > n-1 || j < 0 ||
      visited[i][j] != 0 || grid[i][j] > t 
    ) return false; 
    if(i == n-1 && j == n-1) return true;
    visited[i][j] = 1;
    bool hit = false;
    for(int d = 0; d < 4; d++)
      hit |= dfs(grid, visited, dirs, i+dirs[d][0], j+dirs[d][1], n, t);
    return hit;
  }
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    int l = grid[n-1][n-1], r = (n*n)-1;
    int ans = INF;
    while (l <= r) {
      int m = (l+r)/2;
      vector<vector<int>> visited(n, vector<int>(n, 0));
      if(dfs(grid, visited, dirs, 0, 0, n, m)) {
        ans = min(ans, m);
        r = m-1;
      } else l = m+1;
    }
    return ans;
  }
};


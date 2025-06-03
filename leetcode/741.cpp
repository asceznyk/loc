class Solution {
public:
  int dfs(
    int x1, int y1, int x2, int n,
    vector<vector<int>>& grid, vector<vector<vector<int>>>& mem
  ) {
    int y2 = (x1 + y1) - x2;
    if (
      x1 > n-1 || y1 > n-1 || x2 > n-1 || y2 > n-1 || 
      grid[x1][y1] == -1 || grid[x2][y2] == -1
    ) return INT_MIN;
    if (x1 == n-1 && y1 == n-1) return grid[x1][y1];
    if (x2 == n-1 && y2 == n-1) return grid[x2][y2];
    if (mem[x1][y1][x2] != INT_MIN) return mem[x1][y1][x2];
    int score = max({
      dfs(x1, y1+1, x2, n, grid, mem), dfs(x1+1, y1, x2, n, grid, mem),
      dfs(x1, y1+1, x2+1, n, grid, mem), dfs(x1+1, y1, x2+1, n, grid, mem)
    });
    mem[x1][y1][x2] = score + grid[x1][y1] + (!(x1 == x2 && y1 == y2) ? grid[x2][y2]: 0);
    return mem[x1][y1][x2];
  }
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> mem(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    return max(0, dfs(0, 0, 0, n, grid, mem));
  }
};


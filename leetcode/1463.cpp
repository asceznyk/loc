class Solution {
public:
  int dfs(
    int i, int j, int k,
    vector<vector<int>>& grid,
    vector<vector<vector<int>>>& mem
  ) {
    int m = grid.size(), n = grid[0].size();
    if (j < 0 || j > n-1 || k < 0 || k > n-1) return INT_MIN;
    if (i == m-1) return grid[i][j] + (j != k ? grid[i][k]: 0);
    if (mem[i][j][k] != INT_MIN) return mem[i][j][k];
    int score = INT_MIN;
    for (int p = j-1; p <= j+1; p++) {
      for (int q = k-1; q <= k+1; q++) {
        score = max(
          score, grid[i][j] + (j != k ? grid[i][k]: 0) + dfs(i+1, p, q, grid, mem)
        );
      }
    }
    return mem[i][j][k] = score;
  }
  int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    return dfs(0, 0, n-1, grid, mem);
  }
};



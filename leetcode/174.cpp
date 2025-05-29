class Solution {
public:
  int dfs(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& mem) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    if (i > m-1 || j > n-1) return INT_MIN;
    if (i == m-1 && j == n-1) return min(0, dungeon[i][j]);
    if (mem[i][j] != INT_MIN) return mem[i][j];
    int d = dfs(i+1, j, dungeon, mem);
    int r = dfs(i, j+1, dungeon, mem);
    mem[i][j] = min(0, dungeon[i][j] + max(d, r));
    return mem[i][j];
  }
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> mem(m, vector<int>(n, INT_MIN));
    return 1-dfs(0, 0, dungeon, mem);
  }
};


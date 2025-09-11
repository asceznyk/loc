class Solution {
public:
  int n = 0;
  const int INF = 1e9;
  int dfs(
    int i, int r, vector<int>& cost, vector<int>& time,
    vector<vector<int>>& mem
  ) {
    if (r <= 0) return 0;
    if (i == n) return INF;
    if (mem[i][r] != -1) return mem[i][r]; 
    return mem[i][r] = min(
      cost[i] + dfs(i+1, r-1-time[i], cost, time, mem),
      dfs(i+1, r, cost, time, mem)
    );
  }
  int paintWalls(vector<int>& cost, vector<int>& time) {
    n = cost.size();
    vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
    return dfs(0, n, cost, time, mem);
  }
};


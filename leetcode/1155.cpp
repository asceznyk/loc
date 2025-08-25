class Solution {
public:
  int x = 0;
  const int MOD = 1e9+7;
  int dfs(int n, int s, int target, vector<vector<int>>& mem) {
    if (n == 0 && s == target) return 1;
    if (n == 0 || s > target) return 0;
    if (mem[n][s] != -1) return mem[n][s] % MOD;
    int cnt = 0;
    for (int v = 1; v < x+1; v++) {
      cnt += dfs(n-1, s+v, target, mem);
      cnt %= MOD;
    }
    return mem[n][s] = cnt % MOD;
  }
  int numRollsToTarget(int n, int k, int target) {
    x = k;
    vector<vector<int>> mem(n+1, vector<int>(target+1, -1));
    return dfs(n, 0, target, mem);
  }
};


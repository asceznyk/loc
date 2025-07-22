class Solution {
public:
  int dfs(int k, int l, vector<vector<int>>& mem, int n) {
    if (l == n) return 0;
    if (l > n) return 1005;
    if (mem[k][l] != 0) return mem[k][l];
    int res = min(1+dfs(k, l+k, mem, n), 2+dfs(l, l+l, mem, n));
    return mem[k][l] = res;
  }
  int minSteps(int n) {
    if (n == 1) return 0;
    vector<vector<int>> mem(n+1, vector<int>(n+1));
    int ans = 1+dfs(1, 1, mem, n);
    return ans;
  }
};


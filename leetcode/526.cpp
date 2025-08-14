class Solution {
public:
  int dfs(int i, int d, int n, vector<int>& visited) {
    if (d == n) return (i%d == 0 || d%i == 0 ? 1: 0);
    visited[i] = 1;
    int ways = 0;
    for(int x = 1; x < n+1; x++) {
      if (visited[x]) continue;
      if ((d+1) % x == 0 || x % (d+1) == 0)
        ways += dfs(x, d+1, n, visited);
    }
    visited[i] = 0;
    return ways;
  }
  int countArrangement(int n) {
    vector<int> visited(n+1, 0);
    return dfs(0, 0, n, visited);
  }
};


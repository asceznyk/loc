class Solution {
public:
  int dfs(int n, map<int,int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != 0) return dp[n];
    return dp[n] = 1+min((n%3)+dfs(n/3,dp), (n%2)+dfs(n/2,dp));
  }
  int minDays(int n) {
    map<int,int> dp;
    return dfs(n, dp);
  }
};


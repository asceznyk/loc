class Solution {
public:
  int dfs(
    int i, int m, int n,
    vector<pair<int,int>>& zeroOneCnt,
    vector<vector<vector<int>>>& dp
  ) {
    if (m < 0 || n < 0) return INT_MIN;
    if (i+1 == zeroOneCnt.size()) return 0;
    if (dp[i+1][m][n] != -1) return dp[i+1][m][n];
    return dp[i+1][m][n] = max(
      1+dfs(i+1, m-zeroOneCnt[i+1].first, n-zeroOneCnt[i+1].second, zeroOneCnt, dp),
      dfs(i+1, m, n, zeroOneCnt, dp)
    );
  }
  int findMaxForm(vector<string>& strs, int m, int n) {
    int k = strs.size();
    vector<vector<vector<int>>> dp(
      k+1, vector<vector<int>>(m+1,vector<int>(n+1, -1))
    );
    vector<pair<int,int>> zeroOneCnt;
    for (string s: strs) {
      int zero = 0, one = 0;
      for (int l = 0; l < s.length(); l++) {
        if (s[l]-'0' == 0) zero++;
        else one++;
      }
      zeroOneCnt.push_back({zero,one});
    }
    return dfs(-1, m, n, zeroOneCnt, dp);
  }
};


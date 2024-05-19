class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = (int)s1.size();
    int m = (int)s2.size();
    int l = (int)s3.size();
    if(l != m+n) return false;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n+1; i++) {
      for (int j = 0; j < m+1; j++) {
        if(i >= 1 && s1[i-1] == s3[(i+j)-1]) dp[i][j] |= dp[i-1][j];
        if(j >= 1 && s2[j-1] == s3[(i+j)-1]) dp[i][j] |= dp[i][j-1];
      }
    }
    return dp[n][m];
  }
};

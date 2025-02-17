class Solution {
public:
  bool dfs(int i, int k, vector<int>& stones, vector<vector<int>>& dp) {
    if (i == stones.size()-1) {
      dp[i][k] = 1;
      return dp[i][k];
    }
    if (dp[i][k] != -1) return dp[i][k];
    int curr = stones[i];
    int ans = 0;
    for(int j = i+1; j < stones.size(); j++) {
      int cand = stones[j];
      for (int l = k-1; l <= k+1; l++) {
        if (cand == curr+l && l > 0)
          ans |= dfs(j, l, stones, dp);
      } 
    }
    dp[i][k] = ans;
    return ans;
  }
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = dfs(0, 0, stones, dp);
    return (bool)ans;
  }
};


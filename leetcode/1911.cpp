typedef long long ll;

class Solution {
public: 
  ll maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
    dp[n][0] = 0LL;
    dp[n][1] = 0LL;
    for (int i = n-1; i > -1; i--) {
      ll curr = 1LL*nums[i];
      dp[i][0] = max(dp[i+1][0], -1LL*curr+dp[i+1][1]);
      dp[i][1] = max(dp[i+1][1], curr+dp[i+1][0]);
    }
    return dp[0][1];
  }
};


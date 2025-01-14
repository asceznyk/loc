class Solution {
public:
  int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
    if (l > r)
      return 0;
    if (dp[l][r] != 0) 
      return dp[l][r];
    int maxCoins = nums[l];
    for (int i = l; i < r+1; i++) {
      int coins = (nums[l-1] * nums[i] * nums[r+1]);
      coins += dfs(nums, l, i-1, dp);
      coins += dfs(nums, i+1, r, dp);
      maxCoins = max(maxCoins, coins);
    }
    dp[l][r] = maxCoins;
    return maxCoins;
  }
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    return dfs(nums, 1, n-2, dp);
  }
};




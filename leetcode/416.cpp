// Memoized solve O(n * sum(nums))
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int s = (int)accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if (s%2 || n == 1) return false;
    s /= 2; 
    vector<vector<int>> dp(n, vector<int>(s+1, -1));
    search(nums, (int)nums.size(), s, dp);
    return dp[n-1][s];
  }
private:
  int search(vector<int>& nums, int k, int t, vector<vector<int>>& dp) {
    if (k <= 0) return 0;
    if (t == 0) return 1;
    if (dp[k-1][t] != -1) return dp[k-1][t];
    if(nums[k-1] > t) return dp[k-1][t] = search(nums, k-1, t, dp);
    else return dp[k-1][t] = search(nums, k-1, t-nums[k-1], dp) || search(nums, k-1, t, dp);
  }
};

// DP solve O(n * sum(nums))
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int s = (int)accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if (s%2 || n == 1) return false;
    s /= 2; 
    vector<int> curr (s+1);
    vector<int> prev (s+1); 
    prev[0] = 1;
    for(int i = 1; i < n+1; i++) {
      for(int j = 0; j < s+1; j++)
        curr[j] = prev[j] || ((nums[i-1] > j) ? 0 : prev[j-nums[i-1]]);
      prev = curr;
    }
    return (bool)curr[s];
  }
};

class Solution {
public:
  const int INF = 1e9+7;
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
      int a1 = nums1[i-1], b1 = nums2[i-1], a2 = nums1[i], b2 = nums2[i];
      if (a1 < a2 && b1 < b2) {
        dp[i][0] = min(dp[i-1][0], dp[i][0]);
        dp[i][1] = min(dp[i-1][1]+1, dp[i][1]);
      } 
      if (a1 < b2 && b1 < a2) {
        dp[i][0] = min(dp[i-1][1], dp[i][0]);
        dp[i][1] = min(dp[i-1][0]+1, dp[i][1]);
      }
    }
    return min(dp[n-1][0], dp[n-1][1]); 
  }
};


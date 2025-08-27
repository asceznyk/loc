typedef long long ll;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    if (n < 3) return ans;
    vector<unordered_map<ll,int>> dp(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        ll d = 1LL*nums[i] - 1LL*nums[j];
        int cnt = dp[j][d];
        dp[i][d] += 1 + cnt;
        ans += cnt;
      }
    }
    return ans;
  }
};


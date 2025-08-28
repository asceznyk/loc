class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    vector<int> cnt = {0,0};
    int ans = 0;
    while (l <= r && r < n) {
      cnt[nums[r]]++;
      int winSize = r-l+1;
      while (cnt[0] > k) {
        cnt[nums[l]]--;
        l++;
        winSize = r-l+1;
      }
      ans = max(ans, winSize);
      r++;
    }
    return ans;
  }
};


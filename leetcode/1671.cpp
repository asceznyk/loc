class Solution {
public:
  vector<int> lis(vector<int>& nums, bool reversed) {
    int n = nums.size();
    vector<int> length(n);
    if (!reversed) {
      for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
          if (nums[i] >= nums[k]) continue;
          length[k] = max(length[k], length[i]+1);
        }
      }
      return length;
    }
    for (int k = n-1; k > -1; k--) {
      length[k] = 1;
      for (int i = n-1; i > k; i--) {
        if (nums[i] >= nums[k]) continue;
        length[k] = max(length[k], length[i]+1);
      }
    }
    return length;
  }
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    if (n == 3) return 0;
    vector<int> ltrLIS = lis(nums, false);
    vector<int> rtlLIS = lis(nums, true);
    int ans = 1e9 + 7;
    for (int i = 1; i < n-1; i++) {
      if (
        ltrLIS[i] >= ltrLIS[i+1] && ltrLIS[i] >= ltrLIS[i-1] &&
        nums[i] > nums[i+1] && nums[i] >= nums[i-1]
      ) ans = min(ans, (i+1-ltrLIS[i] + n-i-rtlLIS[i]));
    }
    return (ans == 1e9+7 ? 1) : ans;
  }
};


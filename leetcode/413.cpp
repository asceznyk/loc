class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    if (n < 3) return ans;
    int l = 0, r = 2, off = 0;
    while (r < n) {
      int curr = nums[r], prev = nums[r-1];
      if (r-l+1 >= 3 && curr - prev == prev - nums[r-2]) {
        r++;
        off++;
        ans += off;
        continue;
      }
      while (l < r-1 && curr - prev != prev - nums[r-2]) l++;
      r++;
      off = 0;
    }
    return 0;
  }
};

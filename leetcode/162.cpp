class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n-1;
    while (l <= r) {
      int m = (l+r)/2;
      int lc = (m == 0) ? INT_MIN : nums[m-1];
      int rc = (m == n-1) ? INT_MIN : nums[m+1];
      if(nums[m] >= lc && nums[m] >= rc) return m;
      else if(nums[m] >= lc && nums[m] <= rc) l = m+1;
      else r = m-1;
    }
    return -1;
  }
};

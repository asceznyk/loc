class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int s = 1;
    int c = 0;
    while(r < nums.size() && l <= r) {
      if(nums[r] >= k) {
        r++;
        l = r;
        s = 1;
        continue;
      }
      s *= nums[r];
      if(s >= k) {
        s /= (nums[r] * nums[l]);
        l++;
        continue;
      };
      c += r-l+1;
      r++;
    };
    return c;
  }
};


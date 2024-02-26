#include "utils.h"

class Solution {
public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    int a = 0, b = n-1;
    if(nums.back() > nums.front() || nums.size() == 1) return nums[a];
    while(a <= b) {
      int k = (a+b)/2;
      if(nums[k] >= nums[0]) a = k+1;
      else b = k-1;
    }
    return nums[a];
  }
};

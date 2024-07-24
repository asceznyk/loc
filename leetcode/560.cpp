#include "../utils.h"

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pSum(n, 0);
    int s = 0;
    for(int i = 0; i < n; i++) {
      pSum[i] = nums[i]+s;
      s += nums[i];
    }
    printVector(pSum);
    return 0;
  }
};

int main() {
  Solution solve;
  vector<int> nums = {1,1,1};
  solve.subarraySum(nums, 3);
  nums = {1,2,3};
  solve.subarraySum(nums, 3);
  nums = {1,1,1,1,5,-5,2};
  solve.subarraySum(nums, 0);
  return 0;
}

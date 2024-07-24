#include "../utils.h"

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    int w = 1;
    for(int i = 0; i < n-1; i++) {
      if(nums[i] > nums[i+1]) continue;
      w++;
    }
    printf("w = %d\n", w);
    printf("ans = %d\n", (w >= n-1));
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> nums = {2,4,3};
  solve.checkPossibility(nums);
  nums = {4,2,3};
  solve.checkPossibility(nums);
  nums = {4,2,1};
  solve.checkPossibility(nums);
  nums = {3,4,2,3};
  solve.checkPossibility(nums);
  return 0;
}


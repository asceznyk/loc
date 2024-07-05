#include "../utils.h"

class Solution {
private:
  int findMaxF(vector<int>& nums, int k, int i) {
    int fmax = 0;
    for(int j = i; j > -1; j--) {
      int diff = nums[i] - nums[j];
      if(diff > k) break;
      fmax++;
      k -= diff;
      printf("fmax = %d, k = %d, nums[j] = %d, nums[j-1] = %d\n", fmax, k, nums[j], nums[j-1]);
    }
    return fmax;
  }
public:
  int maxFrequency(vector<int>& nums, int k) {
    int cmax = 0;
    sort(nums.begin(), nums.end());
    printVector(nums);
    for(int i = nums.size()-1; i > -1; i--)
      cmax = max(cmax, findMaxF(nums, k, i)); //binary search this bitch
    printf("cmax = %d\n", cmax);
    return cmax;
  }
};

int main() {
  Solution solve;
  vector<int> nums = {1,2,4};
  solve.maxFrequency(nums, 5);
  nums = {1,4,8,13};
  solve.maxFrequency(nums, 5);
  nums = {3,9,6};
  solve.maxFrequency(nums, 2);
  nums = {2,3,6,6,9,9,9};
  solve.maxFrequency(nums, 5);
  return 0;
}



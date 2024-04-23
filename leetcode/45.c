#include <stdio.h>

int jump(int* nums, int numsSize) {
  if (numsSize == 1 || numsSize == 2) return numsSize-1;
  int dp[numsSize];
  for(int i = 0; i < numsSize; i++) dp[i] = i;
  int k = 0;
  for(int i = 1; i < numsSize; i++) {
    if (k+nums[k] < i) while(k+nums[k] < i) k++;
    int kjump = 1+dp[k];
    dp[i] = kjump < dp[i] ? kjump : dp[i];
  }
  return dp[numsSize-1];
}

int main() {
  int nums1[5] = {2,3,1,1,4};
  jump(nums1, 5);
  int nums2[5] = {2,3,0,1,4};
  jump(nums2, 5);
  int nums3[2] = {2,1};
  jump(nums3, 2);
  int nums4[1] = {0};
  jump(nums4, 1);
  int nums5[7] = {4,1,1,3,1,1,1};
  jump(nums5, 7);
  return 0;
}

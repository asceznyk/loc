#include <stdio.h>

int countWays(int sum, int i, int* nums, int n, int target) {
  if (i >= n-1) return (int)(sum == target);
  return (
    countWays(sum+nums[i+1], i+1, nums, n, target) +
    countWays(sum-nums[i+1], i+1, nums, n, target)
  );
}

int findTargetSumWays(int* nums, int numsSize, int target) {
  int c = countWays(0, -1, nums, numsSize, target);
  return c;
}


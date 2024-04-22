//#include <stdio.h>

#define INF 10000

int dfs(int* nums, int n, int i, int* dp) {
  if (i >= n-1) return 0;
  if (nums[i] == 0) return INF;
  if (dp[i] != INF) return dp[i];
  for(int p = i+1; p <= i+nums[i]; p++) {
    int x = 1+dfs(nums, n, p, dp);
    dp[i] = x < dp[i] ? x : dp[i];
  }
  return dp[i];
}

int jump(int* nums, int numsSize) {
  if (numsSize == 1) return 0;
  int dp[numsSize];
  for(int i = 0; i < numsSize; i++) dp[i] = INF;
  dfs(nums, numsSize, 0, dp);
  return dp[0];
}

/*int main() {
  int nums1[5] = {2,3,1,1,4};
  jump(nums1, 5);
  int nums2[5] = {2,3,0,1,4};
  jump(nums2, 5);
  int nums3[2] = {2,1};
  jump(nums3, 2);
  int nums4[1] = {0};
  jump(nums4, 1);
  return 0;
}*/

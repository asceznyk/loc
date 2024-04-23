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

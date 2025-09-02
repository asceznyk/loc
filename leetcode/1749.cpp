class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0, maxSum = INT_MIN;
    for (int x: nums) {
      sum = max(sum+x, x);
      maxSum = max(maxSum, sum);
    }
    sum = 0;
    int minSum = INT_MAX;
    for (int x: nums) {
      sum = min(sum+x, x);
      minSum = min(minSum, sum);
    }
    return max(maxSum, abs(minSum));
  }
};



class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size(), maxVal = 0, count = 0;
    for (int b = 0; b < (1<<n); b++) {
      int score = 0;
      for (int i = 0; i < n; i++)
        if (b&(1<<i)) score |= nums[i];
      if (score > maxVal) {
        maxVal = score;
        count = 1;
      } else if (score == maxVal) count++;
    }
    return count;
  }
};



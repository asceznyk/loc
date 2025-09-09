class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, prev = 0, cnt = 0;
    for (int curr: nums) {
      if (curr == prev && prev == 1) cnt++;
      else cnt = (curr == 1 ? 1 : 0);
      ans = max(ans, cnt);
      prev = curr;
    }
    return ans;
  }
};

class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int l = 0, r = 0, end = -1;
    int ans = 0;
    int n = nums.size();
    vector<int> cnts(2);
    while (r < n && l <= r) {
      int curr = nums[r]%2;
      cnts[curr]++;
      if (cnts[1] == k && curr == 1) end = r;
      if (cnts[1] > k || r == n-1) {
        r -= (cnts[1] > k ? 1: 0);
        cnts[1] -= (cnts[1] > k ? 1: 0);
        while (cnts[1] == k) {
          ans += (r-end+1);
          cnts[nums[l]%2]--;
          l++;
        }
      }
      r++;
    }
    return ans;
  }
};



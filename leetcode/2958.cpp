class Solution {
public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int ans = 1, n = nums.size();
    if (n == ans) return ans;
    int l = 0, r = 0;
    unordered_map<int,int> freq;
    while (l <= r && r < n) {
      int curr = nums[r];
      freq[curr]++;
      while (freq.find(curr) != freq.end() && freq[curr] > k) {
        freq[nums[l]]--;
        l++;
      }
      ans = max(ans, r-l+1);
      r++;
    }
    return ans;
  }
};


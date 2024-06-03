class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixs(n+1, 0);
    for(int i = 1; i < n+1; i++) prefixs[i] = prefixs[i-1] + nums[i-1];
    int ans = 100005;
    int l = 0, r = 0;
    while (l <= r && r < n) {
      int s = prefixs[r+1] - prefixs[l];
      if(s >= target) {
        ans = min(r-l+1, ans);
        l++;
        continue;
      }
      r++;
    } 
    return ans == 100005 ? 0 : ans;
  }
};


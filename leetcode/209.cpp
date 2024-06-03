class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int p = 0;
    vector<int> prefixs(n, 0);
    for(int i = 0; i < n; i++) {
      p += nums[i];
      prefixs[i] = p;
    }
    int ans = 100005;
    int l = 0, r = 0; 
    while (l <= r && r < n) {
      int s = l > 0 ? prefixs[r] - prefixs[l-1] : prefixs[r];
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


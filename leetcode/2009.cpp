class Solution {
public:
  int minOperations(vector<int>& nums) {
    const int INF = 1e6+7;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int m = nums.size(), r = 0, ans = n-m;
    int ops = INF;
    for (int l = 0; l < m; l++) {
      int maxE = nums[l] + (n-1);
      r = lower_bound(nums.begin(), nums.end(), maxE) - nums.begin();
      if (r >= m) {
        ops = min(ops, l);
        break;
      };
      ops = min(ops, (l+m-r-1)+(nums[r] > maxE ? 1 : 0));
    }
    ans += (ops == INF ? 0: ops);
    return ans;
  }
};


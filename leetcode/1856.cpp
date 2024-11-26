typedef long long int lli;

const lli MOD = 1000000007;

class Solution {
public:
  int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<lli> prefix = {0};
    for (auto x: nums)
      prefix.push_back(x+prefix[prefix.size()-1]);
    lli ans = 0;
    vector<pair<lli,int>> vstack;
    for(int i = 0; i < n; i++) {
      lli x = nums[i];
      int j = i;
      while (!vstack.empty() && vstack.back().first > x) {
        pair<lli,int> p = vstack.back();
        j = p.second;
        ans = max(ans, p.first*(prefix[i]-prefix[j]));
        vstack.pop_back();
      }
      vstack.push_back({x,j});
    }
    for (auto p: vstack)
      ans = max(ans, p.first*(prefix[n]-prefix[p.second]));
    return (int)(ans % MOD);
  }
};

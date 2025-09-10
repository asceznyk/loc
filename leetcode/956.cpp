class Solution {
public:
  int n = 0;
  int tallestBillboard(vector<int>& rods) {
    n = rods.size();
    map<int,int> dp;
    dp[0] = 0;
    for (int r: rods) {
      map<int,int> newDp(dp);
      for (auto entry: dp) {
        int d = entry.first;
        int t = entry.second;
        int s = t-d;
        int x = abs((s+r)-t);
        newDp[d+r] = max(newDp.count(d+r) > 0 ? newDp[d+r] : 0, t+r);
        newDp[x] = max(newDp.count(x) > 0 ? newDp[x] : 0, max(s+r, t));
      }
      dp = newDp;
    }
    return dp.count(0) > 0 ? dp[0] : 0;
  }
};


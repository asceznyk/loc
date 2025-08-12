class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    int ans = 0;
    int tsum = neededTime[0], tmax = neededTime[0];
    char prev = colors[0];
    for (int i = 1; i < colors.size(); i++) {
      int curr = colors[i];
      if (curr == prev) {
        tsum += neededTime[i];
        tmax = max(tmax, neededTime[i]);
        prev = curr;
        continue;
      }
      ans += (tsum - tmax);
      tsum = neededTime[i];
      tmax = neededTime[i];
      prev = curr;
    }
    ans += (tsum - tmax)
    return ans;
  }
};


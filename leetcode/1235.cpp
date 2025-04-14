class Solution {
public:
  int dfs(
    int i, vector<vector<int>>& schedules,
    vector<int>& startTime, vector<int>& dp
  ) {
    if (i >= schedules.size()) return 0;
    if (dp[i] != 0) return dp[i];
    int end = schedules[i][1];
    auto it = lower_bound(startTime.begin(), startTime.end(), end);
    int j = it - startTime.begin();
    dp[i] = max(
      dfs(i+1, schedules, startTime, dp),
      schedules[i][2] + dfs(j, schedules, startTime, dp)
    );
    return dp[i];
  }
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> schedules(n+1, vector<int>(3));
    for (int i = 1; i < n+1; i++) {
      schedules[i][0] = startTime[i-1];
      schedules[i][1] = endTime[i-1];
      schedules[i][2] = profit[i-1];
    }
    sort(schedules.begin(), schedules.end(),
      [](const vector<int>& a, const vector<int>& b) {
      return !a.empty() && !b.empty() && a[0] < b[0];
    });
    startTime.push_back(0);
    sort(startTime.begin(), startTime.end());
    schedules[0][1] = startTime[1];
    vector<int> dp(n+1);
    return dfs(0, schedules, startTime, dp);
  }
};


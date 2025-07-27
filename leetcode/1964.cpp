class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<int> temp;
    temp.push_back(obstacles[0]);
    int len = 1;
    vector<int> dp(n);
    dp[0] = len;
    for (int i = 1; i < n; i++) {
      int curr = obstacles[i];
      if (curr >= temp.back()) {
        temp.push_back(curr);
        len++;
        dp[i] = len;
      } else {
        int j = upper_bound(temp.begin(), temp.end(), curr) - temp.begin();
        dp[i] = (curr == temp[j]) ? (2 + j) : (1 + j); 
        temp[j] = obstacles[i];
      }
    }
    return dp;
  }
};


typedef long long ll;

class Solution {
public:
  ll dfs(int i, vector<vector<int>>& questions, vector<ll>& dp) {
    if (i >= (int)questions.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(
      dfs(i+1, questions, dp),
      questions[i][0]+dfs(i+questions[i][1]+1, questions, dp)
    );
  }
  ll mostPoints(vector<vector<int>>& questions) {
    vector<ll> dp(questions.size()+1, -1);
    return dfs(0, questions, dp);
  }
};


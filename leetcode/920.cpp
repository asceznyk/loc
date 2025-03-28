typedef long long ll;
const int MOD = 1e9+7;

class Solution {
public:
  int n, goal, k;
  ll dfs(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1LL;
    if (i == 0 || j == 0) return 0LL;
    if (dp[i][j] != -1) return dp[i][j];
    ll res = 0;
    dp[i][j] = (dfs(i-1, j-1, dp) * (n-j+1) % MOD);
    dp[i][j] += (j < k) ? 0 : (dfs(i-1, j, dp) * (j-k) % MOD);
    return dp[i][j];
  }
  int numMusicPlaylists(int n, int goal, int k) {
    this->n = n;
    this->k = k;
    this->goal = goal;
    if (goal < n) {
      return 0;
    }
    vector<vector<int>> dp(goal+1, vector<int>(n+1, -1));
    return (int)(dfs(goal, n, dp) % MOD);
  }
};

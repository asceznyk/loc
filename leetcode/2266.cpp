const int MOD = (int)1e9 + 7;

class Solution {
private:
  int dfs(string& pressedKeys, vector<int>& dp, int i, int n) {
    if (i >= n-1) return 1;
    if (dp[i+1] != -1) return dp[i+1] % MOD;
    char s = pressedKeys[i+1];
    int c = 0;
    for(int j = 0; j < (s == '7' || s == '9' ? 4 : 3); j++) {
      if(pressedKeys[i+j+1] != s) break;
      c += dfs(pressedKeys, dp, i+j+1, n);
      c %= MOD;
    }
    dp[i+1] = (c % MOD);
    return c;
  }
public:
  int countTexts(string pressedKeys) {
    int n = pressedKeys.length();
    vector<int> dp(n+1, -1);
    return dfs(pressedKeys, dp, -1, n);
  }
};



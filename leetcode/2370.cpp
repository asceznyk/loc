class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.length();
    vector<int> dp(n, 1);
    vector<int> lastIdx(26, INT_MAX);
    lastIdx[s[0]-'a'] = 0;
    int ans = 1;
    for (int i = 1; i < n; i++) {
      int x = s[i]-'a';
      for (int c = 0; c < 26; c++) {
        if (abs(c-x) > k || lastIdx[c] > i) continue;
        dp[i] = max(dp[lastIdx[c]]+1, dp[i]);
      }
      ans = max(ans, dp[i]);
      lastIdx[x] = i;
    }
    return ans;
  }
};


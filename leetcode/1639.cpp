typedef long long int lli;

class Solution {
public:
  int m = 0, n = 0, g = 0;
  const int MOD = 1e9+7;
  lli dfs(
    int k, int i,
    vector<vector<int>>& freq, string target,
    vector<vector<int>>& mem
  ) {
    if (i == g) return 1;
    if (k >= n || n-k < g-i) return 0;
    if (mem[k][i] != -1) return mem[k][i];
    lli ways = (freq[target[i]-'a'][k] * dfs(k+1, i+1, freq, target, mem)) % MOD;
    ways += dfs(k+1, i, freq, target, mem);
    ways %= MOD;
    return mem[k][i] = ways % MOD;
  }
  int numWays(vector<string>& words, string target) {
    m = words.size(), n = words[0].length(), g = target.length();
    int ans = 0;
    if (g > n) return ans;
    vector<vector<int>> freq(26, vector<int>(n));
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        int w = words[i][k]-'a';
        freq[w][k]++;
      }
    }
    vector<vector<int>> mem(n, vector<int>(g, -1));
    return dfs(0, 0, freq, target, mem);
  }
};



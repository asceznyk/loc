class Solution {
public:
  int dfs(int i, int j, string& s, vector<vector<int>>& mem) {
    if (i > j) return 0;
    if (mem[i][j] != -1) return mem[i][j];
    int mturns = 1+dfs(i+1, j, s, mem);
    for (int k = i+1; k <= j; k++) {
      if (s[i] != s[k]) continue;
      mturns = min(mturns, dfs(i, k-1, s, mem) + dfs(k+1, j, s, mem));
    } 
    return mem[i][j] = mturns;
  }
  string removeConsecDuplicates(string& s) {
    string uniqStr;
    int i = 0;
    while (i < s.length()) {
      char curr = s[i];
      uniqStr += curr;
      while (i < s.length() && s[i] == curr) i++;
    }
    return uniqStr;
  }
  int strangePrinter(string s) {
    s = removeConsecDuplicates(s);
    int n = s.length();
    vector<vector<int>> mem(n, vector<int>(n, -1));
    int turns = dfs(0, n-1, s, mem);
    return turns;      
  }
};



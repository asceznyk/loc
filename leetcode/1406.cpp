class Solution {
public:
  int dfs(int i, int p, vector<int>& stoneValue, vector<vector<int>>& mem) {
    int n = stoneValue.size();
    if (i > n-1) return 0;
    if (i == n-1) return stoneValue[n-1];
    if (mem[i][p] != INT_MIN) return mem[i][p];
    int score = INT_MIN;
    int prefix = 0;
    for (int j = i; j < i+3; j++) {
      if (j > n-1) continue;
      prefix += stoneValue[j];
      score = max(score, prefix-dfs(j+1, p^1, stoneValue, mem));
    }
    mem[i][p] = score;
    return mem[i][p];
  }
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<vector<int>> mem(n, vector<int>(2, INT_MIN));
    int res = dfs(0, 0, stoneValue, mem);
    if (res > 0) return "Alice";
    else if(res < 0) return "Bob";
    else return "Tie";
  }
};

class Solution {
public:
  int dfs(int i, int m, int p, vector<int>& piles, vector<vector<vector<int>>>& mem) {
    int n = piles.size();
    if (i > n-1) return 0;
    if (i == n-1) return (p == 0) ? piles[n-1] : 0;
    if (mem[i][m][p] != INT_MIN) return mem[i][m][p];
    int score = (p == 0) ? INT_MIN : INT_MAX, x = 0, mpref = 0, prefix = 0;
    for (int j = i; j < i+(2*m); j++) {
      if (j > n-1) continue;
      x++;
      prefix += piles[j];
      int calc = dfs(j+1, max(m,x), p^1, piles, mem);
      if (p == 0) score = max(score, prefix+calc);
      else score = min(score, calc);
    }
    mem[i][m][p] = score;
    return mem[i][m][p];
  }
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<vector<int>>> mem(n, vector<vector<int>>(n, vector<int>(2, INT_MIN)));
    return  dfs(0, 1, 0, piles, mem);
  }
};


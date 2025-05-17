class Solution {
public:
  int dfs(int i, int m, vector<int>& piles, vector<vector<int>>& mem) {
    int n = piles.size();
    if (i > n-1) return 0;
    if (mem[i][m] != INT_MIN) return mem[i][m];
    int score = INT_MIN, mpref = 0, prefix = 0;
    for (int j = i; j < i+(2*m); j++) {
      if (j > n-1) continue;
      prefix += piles[j];
      score = max(score, prefix-dfs(j+1, max(m,(j-i)+1), piles, mem));
    } 
    return mem[i][m] = score;
  }
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> mem(n, vector<int>(n+1, INT_MIN));
    int total = accumulate(piles.begin(), piles.end(), 0);
    return (total+dfs(0, 1, piles, mem))/2;
  }
};


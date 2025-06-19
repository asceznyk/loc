class Solution {
public:
  int dfs(int n, vector<int>& mem) {
    if (n <= 0) return -1;
    if (mem[n] != INT_MIN) return mem[n]; 
    int score = INT_MIN;
    for (int i = 1; (i*i) <= n; i++) {
      score = max(score, -dfs(n-(i*i), mem));
    }
    return mem[n] = score;
  }
  bool winnerSquareGame(int n) {
    vector<int> mem(n+1, INT_MIN);
    return dfs(n, mem) == 1;
  }
};


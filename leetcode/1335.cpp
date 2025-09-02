class Solution {
public:
  int n = 0;
  const int INF = 1e5;
  int dfs(
    int i, int d,
    vector<int>& jobDifficulty, vector<vector<int>>& mem
  ) {
    if (i == n) return INF;
    if (d == 0) return *max_element(jobDifficulty.begin()+i, jobDifficulty.end());
    if (mem[i][d] != -1) return mem[i][d];
    int res = INF;
    int diff = jobDifficulty[i];
    for (int j = i+1; j < (n-d)+1; j++) {
      res = min(diff+dfs(j, d-1, jobDifficulty, mem), res);
      diff = max(diff, jobDifficulty[j]);
    }
    return mem[i][d] = res;
  }
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    n = jobDifficulty.size();
    vector<vector<int>> mem(n+1, vector<int>(d, -1));
    int ans = 0;
    if (d > n) return -1;
    if (accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0) == 0) return ans;
    ans = dfs(0, d-1, jobDifficulty, mem);
    return ans;
  }
};



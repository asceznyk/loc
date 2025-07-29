class Solution {
public:
  int dfs(int i, int k, vector<int>& arr, vector<int>& mem) {
    int n = arr.size();
    if (i >= n) return 0;
    if (mem[i] != -1) return mem[i];
    int res = 0, emax = 0;
    for (int j = i+1; j <= min(n, i+k); j++) {
      emax = max(arr[j-1], emax);
      res = max(emax*(j-i) + dfs(j, k, arr, mem), res);
    }
    return mem[i] = res;
  }
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> mem(n, -1);
    return dfs(0, k, arr, mem);
  }
};


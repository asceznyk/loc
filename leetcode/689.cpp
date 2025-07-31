class Solution {
public:
  int dfs(
    int i, int t, int k,
    vector<int>& prefix, vector<vector<int>>& mem
  ) {
    int n = prefix.size();
    if (t == 0) return 0;
    if (i >= n-k) return (t > 0 ? INT_MIN : 0);
    if (mem[i][t] != -1) return mem[i][t];
    int skip = dfs(i+1, t, k, prefix, mem);
    int take = (prefix[i+k] - prefix[i]) + \
               dfs(i+k, t-1, k, prefix, mem);
    return mem[i][t] = max(skip, take);
  }
  void reconst(
    int i, int t, int k,
    vector<int>& indices, vector<int>& prefix,
    vector<vector<int>>& mem
  ) {
    int n = prefix.size();
    if (i >= n-k || t == 0) return;
    int skip = dfs(i+1, t, k, prefix, mem);
    int take = (prefix[i+k] - prefix[i]) + \
               dfs(i+k, t-1, k, prefix, mem);
    if (take >= skip) {
      indices.push_back(i);
      reconst(i+k, t-1, k, indices, prefix, mem);
    } else reconst(i+1, t, k, indices, prefix, mem);
  } 
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n+1);
    int p = 0;
    for(int i = 0; i < n; i++) {
      p += nums[i];
      prefix[i+1] = p;
    }
    vector<int> indices;
    vector<vector<int>> mem(n+1, vector<int>(4, -1));
    int maxSum = dfs(0, 3, k, prefix, mem);
    reconst(0, 3, k, indices, prefix, mem);
    return indices;
  }
};



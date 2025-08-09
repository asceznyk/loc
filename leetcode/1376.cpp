class Solution {
public:
  int dfs (
    int i,
    unordered_map<int,vector<int>>& adj,
    vector<int>& informTime
  ) {
    int res = 0;
    for (int j: adj[i])
      res = max(res, informTime[i]+dfs(j, adj, informTime));
    return res;
  }
  int numOfMinutes(
    int n, int headID,
    vector<int>& manager, vector<int>& informTime
  ) {
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
      int cur = manager[i];
      if (cur == -1) continue;
      adj[cur].push_back(i);
    }
    return dfs(headID, adj, informTime);
  }
};


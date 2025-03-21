typedef long long ll;

class Solution {
public:
  int ans = 0;
  ll dfs(
    int u, int p, int k, vector<int>& values,
    map<int,vector<int>>& adjList
  ) {
    ll curr = values[u];
    if ((int)adjList[u].size() == 0) {
      if (curr % k != 0) {
        ans--;
        return curr;
      }
      return 0LL;
    }
    ll nsum = curr;
    for(auto& q: adjList[u]) {
      if (q == p) continue;
      ll inter = dfs(q, u, k, values, adjList);
      nsum += inter;
    }
    if (nsum % k != 0) {
      ans--;
      return nsum;
    }
    return 0LL;
  }
  int maxKDivisibleComponents(
    int n, vector<vector<int>>& edges, vector<int>& values, int k
  ) {
    map<int,vector<int>> adjList;
    for (auto& edge: edges) {
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    }
    ans = n;
    dfs(0, -1, k, values, adjList);
    return ans;
  }
};


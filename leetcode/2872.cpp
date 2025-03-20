typedef long long ll;

class Solution {
public:
  int ans = 0;
  ll dfs(
    int i, int k, vector<int>& values,
    map<int,vector<int>>& adjList, vector<int>& visited
  ) {
    ll curr = values[i];
    if ((int)adjList[i].size() == 0) {
      if (curr % k != 0) {
        ans--;
        return curr;
      }
      return 0LL;
    }
    visited[i] = 1;
    ll nsum = curr;
    for(auto& j: adjList[i]) {
      if (visited[j]) continue;
      ll inter = dfs(j, k, values, adjList, visited);
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
    vector<int> visited(n);
    dfs(0, k, values, adjList, visited);
    return ans;
  }
};


class Solution {
private:
  void dfs(vector<int> graph[], vector<int>& visited, int u) {
    visited[u] = 1;
    for(auto v: graph[u]) {
      if (visited[v]) continue;
      dfs(graph, visited, v);
    }
  }
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int count = 0;
    vector<int> graph[n];
    for(auto e: edges) graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++) {
      if (visited[i]) continue;
      dfs(graph, visited, i);
      count++;
    }
    return count;
  }
};

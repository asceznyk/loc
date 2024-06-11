class Solution {
  void dfs(vector<vector<int>>& graph, vector<int>& visited, int i, int b) {
    if(visited[i] != -1) {
      visited[i] = (visited[i] != b) ? 2: visited[i];
      return;
    };
    visited[i] = b;
    bool x = true;
    for(int j = 0; j < graph[i].size(); j++) dfs(graph, visited, graph[i][j], 1^b);
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if(n == 1) return true;
    vector<int> visited(n, -1);
    for(int i = 0; i < n; i++) {
      if(visited[i] != -1) {
        if(visited[i] == 2) return false;
      };
      dfs(graph, visited, i, 0);
    }
    return true;
  }
};


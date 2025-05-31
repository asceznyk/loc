class Solution {
public:
  pair<bool,int> dfs(
    int v, vector<vector<int>>& graph, vector<int>& visited, vector<bool>& isBad
  ) {
    int numNodes = 0;
    visited[v] = 1;
    bool mal = isBad[v];
    for (int k = 0; k < graph[v].size(); k++) {
      if (graph[v][k] == 0 || v == k || visited[k] == 1) continue;
      auto [rMal, rNodes] = dfs(k, graph, visited, isBad);
      numNodes += 1+rNodes;
      mal |= rMal;
    }
    return {mal, numNodes};
  }
  int disconnect(
    int v, vector<vector<int>>& graph, vector<int>& visited, vector<bool>& isBad
  ) {
    int numInfected = 0;
    vector<pair<int,int>> coords;
    for (int k = 0; k < graph[v].size(); k++) {
      if(graph[v][k] == 1 && v != k) {
        graph[v][k] = 0;
        graph[k][v] = 0;
        coords.push_back({v, k});
      };
    }
    for (int k = 0; k < graph[v].size(); k++) {
      if (visited[k] || k == v || graph[v][k] == 1) continue;
      auto [isMal, nCurr] = dfs(k, graph, visited, isBad);
      nCurr++;
      numInfected += (isMal ? nCurr : 0);
    }
    for (auto& p: coords) {
      auto [v, k] = p;
      graph[v][k] = 1;
      graph[k][v] = 1;
    }
    fill(visited.begin(), visited.end(), 0);
    return numInfected;
  }
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& infected) {
    int n = graph.size();
    vector<bool> isBad(n);
    for (auto& node: infected) isBad[node] = true;
    vector<int> visited(n);
    int minNodes = 301, ans = 301;
    for (auto& node: infected) {
      int numInfected = disconnect(node, graph, visited, isBad);
      if (numInfected < minNodes) {
        minNodes = numInfected;
        ans = node;
      } else if (numInfected == minNodes) ans = min(ans, node);
    }
    return ans;
  }
};


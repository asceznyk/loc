class Solution {
private:
  int zeroPass(
    vector<vector<int>>& graph, int cur, int par, 
    int depth, vector<int>& underlings
  ) {
    int dist = 0;
    underlings[cur]++;
    for (int j = 0; j < graph[cur].size(); j++) {
      int child = graph[cur][j];
      if (child == par) continue;
      dist += zeroPass(graph, child, cur, depth+1, underlings);
      underlings[cur] += underlings[child];
    }
    return dist+depth;
  }
  void dfs(
    vector<vector<int>>& graph, int cur, int par,
    vector<int>& underlings, vector<int>& res
  ) {
    if(cur != 0) res[cur] = res[par] + underlings[0] - (2*underlings[cur]);
    for (int j = 0; j < graph[cur].size(); j++) {
      int child = graph[cur][j];
      if (child == par) continue;
      dfs(graph, child, cur, underlings, res);
    }
  }
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto e: edges) {
      int a = e[0], b = e[1];
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    vector<int> res(n);
    vector<int> underlings(n);
    res[0] = zeroPass(graph, 0, -1, 0, underlings);
    dfs(graph, 0, -1, underlings, res);
    return res;
  }
};

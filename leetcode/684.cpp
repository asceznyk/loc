class Solution {
private:
  int start = -1;
  bool *cycle, *visited, found{};
  void dfs(vector<int> graph[], int cur, int prt=-1) {
    if(visited[cur]) { start = cur; found = true; return; }
    visited[cur] = true;
    for(auto child: graph[cur]) {
      if(child == prt) continue;
      if(!found) dfs(graph, child, cur);
      if(start != -1) cycle[cur] = true;
      if(cur == start) { start = -1; break;}
    }
  }
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> graph[n+1];
    start = -1;
    found = false;
    cycle = (bool*)calloc(n+1, sizeof(bool));
    visited = (bool*)calloc(n+1, sizeof(bool));
    for(auto e: edges) graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    dfs(graph, 1);
    vector<int> r;
    for(int i = n-1; ~i; i--)
      if(cycle[edges[i][0]] && cycle[edges[i][1]]) {  r = edges[i]; break; }
    free(cycle);
    free(visited);
    return r;
  }
};

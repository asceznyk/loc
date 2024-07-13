class Solution {
private:
  int dfs(
      vector<vector<int>>& adjList,
      vector<bool>& hasApple,
      unordered_map<string, int>& edgeY,
      vector<int>& visited,
      int i
      ) {
    if(visited[i]) return 0;
    int res = 0;
    visited[i] = 1;
    for(auto k: adjList[i]) {
      int x = dfs(adjList, hasApple, edgeY, visited, k);
      edgeY[to_string(i)+"_"+to_string(k)] = x;
      edgeY[to_string(k)+"_"+to_string(i)] = x;
      res |= x;
    }
    return res | hasApple[i];
  }
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> adjList(n);
    vector<int> visited(n);
    unordered_map<string, int> edgeY;
    for(auto e: edges) {
      int a = e[0], b = e[1];
      adjList[a].push_back(b);
      adjList[b].push_back(a);
      edgeY[to_string(a)+"_"+to_string(b)] = 0;
      edgeY[to_string(b)+"_"+to_string(a)] = 0;
    }
    dfs(adjList, hasApple, edgeY, visited, 0);
    int ans = 0;
    for(const auto &x: edgeY) ans += x.second;
    return ans;
  }
};


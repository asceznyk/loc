class Solution {
public:
  vector<int> epath;
  void dfs(
    int node,
    unordered_map<int,vector<int>>& graph,
    unordered_map<int,int>& outEdges
  ) {
    if (outEdges[node] == 0) {
      epath.push_back(node);
      return;
    }
    while (graph[node].size()) {
      outEdges[node]--;
      int child = graph[node].back();
      graph[node].pop_back();
      dfs(child, graph, outEdges);
    }
    epath.push_back(node);
  }
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    epath.clear();
    vector<vector<int>> res;
    unordered_map<int,vector<int>> graph;
    unordered_map<int,int> outEdges;
    unordered_map<int,int> inEdges;
    for (auto& p: pairs) {
      int start = p[0], end = p[1]; 
      graph[start].push_back(end);
      outEdges[start]++;
      inEdges[end]++;
    };
    int start = pairs[0][0];
    for (auto& [node, _]: graph) {
      if ((outEdges[node] - inEdges[node]) == 1) {
        start = node;
        break;
      }
    }
    dfs(start, graph, outEdges);
    for (int i = epath.size()-1; i > -1; i--) {
      vector<int> edge = {epath[i+1], epath[i]};
      res.push_back(edge);
    }
    return res;
  }
};


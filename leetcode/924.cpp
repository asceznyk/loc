class DSU {
public:
  vector<int> parent, depth;
  DSU(int n) {
    parent.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;
    if (depth[rootY] > depth[rootX]) {
      parent[rootX] = rootY;
      depth[rootY]++;
    } else {
      parent[rootY] = rootX;
      depth[rootX]++;
    }
  }
};

class Solution {
public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& infected) {
    int n = graph.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][j] == 0 || j == i) continue;
        dsu.unionSet(i, j);
      }
    }
    vector<int> cntNodes(n);
    for (int i = 0; i < n; i++) cntNodes[dsu.find(i)]++; // num. nodes in each component
    int minNodes = 301, ans = 301;
    vector<int> freq(n);
    for (auto& node: infected) freq[dsu.find(node)]++; // num. root present in infected
    for (auto& node: infected) {
      int root = dsu.find(node);
      freq[root]--;
      int affected = 0;
      for (int u = 0; u < freq.size(); u++) {
        if (freq[u] == 0) continue;
        affected += cntNodes[u];
      }
      if (affected < minNodes) {
        minNodes = affected;
        ans = node;
      } else if (affected == minNodes) ans = min(ans, node);
      freq[root]++;
    }
    return ans;
  }
};


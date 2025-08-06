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
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    unordered_map<int,vector<int>> adjList;
    DSU dsu(n);
    for (auto &edge: edges) {
      int a = edge[0], b = edge[1];
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    map<int, vector<int>> nodeVals;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
      int v = vals[i];
      maxVal = max(maxVal, v);
      nodeVals[v].push_back(i);
    }
    int ans = n;
    for (auto& [v, nodes]: nodeVals) {
      for (int i: nodes) {
        for (int j: adjList[i]) {
          if(v < vals[j]) continue;
          dsu.unionSet(i, j);
        }
      }
      unordered_map<int,int> grpCnt;
      for (int i: nodes) grpCnt[dsu.find(i)]++;
      for (auto& [_, cnt]: grpCnt) ans += (cnt*(cnt-1))/2;
    }
    return ans; 
  }
};


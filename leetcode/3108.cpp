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
  vector<int> minimumCost(
    int n,
    vector<vector<int>>& edges,
    vector<vector<int>>& query
  ) {
    int m = query.size();
    vector<int> res(m);
    DSU dsu(n);
    vector<int> dists(n, INT_MAX); 
    for (auto& edge: edges) {
      int x = edge[0], y = edge[1];
      dsu.unionSet(x, y);
    }
    for (auto& edge: edges) {
      int x = edge[0], w = edge[2];
      dists[dsu.find(x)] &= w;
    }
    for (int i = 0; i < m; i++) {
      int x = query[i][0], y = query[i][1];
      int root = dsu.find(x);
      if (root != dsu.find(y)) {
        res[i] = -1;
        continue;
      }
      res[i] = dists[root];
    }
    return res;
  }
};


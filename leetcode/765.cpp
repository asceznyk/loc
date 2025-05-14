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
  int minSwapsCouples(vector<int>& row) {
    int n = row.size()/2;
    DSU dsu(2*n);
    for (int i = 0; i < n; i++)
      dsu.unionSet(row[2*i], row[(2*i)+1]); 
    for (int i = 0; i < n; i++) {
      printf("a = %d, b = %d\n", 2*i, 2*i+1);
      dsu.unionSet(2*i, (2*i)+1);
    }
    set<int> comps;
    for (int i = 0; i < 2*n; i++) comps.insert(dsu.find(i));
    int c = comps.size();
    return n-c; 
  }
};


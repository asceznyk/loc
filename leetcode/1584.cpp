int find(vector<int>& link, int x) {
  while(x != link[x]) x = link[x];
  return x;
}

bool same(vector<int>& link, int a, int b) {
  return find(link, a) == find(link, b);
}

void unite(vector<int>& link, vector<int>& sizes, int a, int b) {
  a = find(link, a);
  b = find(link, b);
  if(sizes[a] < sizes[b]) {
    int t = a;
    a = b;
    b = t;
  }
  sizes[a] += sizes[b];
  link[a] = b;
}

bool compareLast(const vector<int>& a, const vector<int>& b) { 
  return a.back() < b.back();
}

class Solution {
private:
  int manhattanDist(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<int>> edges;
    int n = points.size();
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        vector<int> e = {i, j, manhattanDist(points[i], points[j])};
        edges.push_back(e);
      }
    }
    sort(edges.begin(), edges.end(), compareLast);
    vector<int> link(n);
    for(int i = 0; i < n; i++) link[i] = i;
    vector<int> sizes(n,1);
    int total = 0;
    for(int k = 0; k < edges.size(); k++) {
      int a = edges[k][0], b = edges[k][1], w = edges[k][2];
      if(!same(link, a, b)) {
        unite(link, sizes, a, b);
        total += w;
      }
    }
    return total;
  }
};

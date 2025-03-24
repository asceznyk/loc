class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    deque<pair<int,int>> dq;
    dq.push_front({0,0});
    dist[0][0] = 0;
    while (!dq.empty()) {
      pair<int,int> p = dq.front(); dq.pop_front();
      int i = p.first, j = p.second;
      for (auto& d: dirs) {
        int di = i+d[0], dj = j+d[1];
        if (di < 0 || di > m-1 || dj < 0 || dj > n-1) continue;
        int w = grid[di][dj];
        if (dist[i][j]+w < dist[di][dj]) {
          dist[di][dj] = dist[i][j]+w;
          if (!w) dq.push_front({di,dj});
          else dq.push_back({di,dj});
        }
      }
    }
    return dist[m-1][n-1];
  }
};



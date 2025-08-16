class Solution {
public:
  int minimumTime(vector<vector<int>>& grid) {
    if (grid[1][0] > 1 && grid[0][1] > 1)
      return -1;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    auto compareVec = [](const vector<int>& a, const vector<int>& b) {
      return a[0] > b[0]; 
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compareVec)> pq(compareVec);
    pq.push(vector<int>{0,0,0});
    vector<vector<int>> time(m, vector<int>(n, INT_MAX));
    time[0][0] = 0;
    while (!pq.empty()) {
      vector<int> p = pq.top(); pq.pop();
      int t = p[0], i = p[1], j = p[2];
      if (t > time[i][j]) continue;
      for (auto& d: dirs) {
        int di = i+d[0], dj = j+d[1];
        if (
          di < 0 || di > m-1 || dj < 0 || dj > n-1
        ) continue;
        int x = t+1;
        if (x < grid[di][dj]) {
          int w = grid[di][dj];
          w += (t%2 == w%2 ? 1: 0);
          x = w;
        }
        if (x < time[di][dj]) {
          time[di][dj] = x;
          pq.push({time[di][dj], di, dj});
        }
      }
    }
    return time[m-1][n-1];
  }
};


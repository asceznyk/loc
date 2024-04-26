#include <queue>

vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

class Solution {
private:
  void dijkstra(vector<vector<int>>& grid, int i, int j) {
    vector<vector<int>> visited((int)grid.size(), vector<int>((int)grid[0].size()));
    priority_queue<pair<int, vector<int>>> pq;
    pq.push({0, {i, j}});
    while(!pq.empty()) {
      vector<int> coords = pq.top().second; pq.pop();
      i = coords[0], j = coords[1];
      for(auto d: dirs) {
        int di = i+d[0], dj = j+d[1];
        if (
          di > (int)grid.size()-1 || di < 0 || dj > (int)grid[0].size()-1 || dj < 0 ||
          grid[di][dj] <= 0 || visited[di][dj] != 0 
        ) continue;
        if (1+grid[i][j] < grid[di][dj]) {
          visited[di][dj] = 1;
          grid[di][dj] = 1+grid[i][j];
          pq.push({-grid[di][dj], {di, dj}});
        }
      }
    }
  }
public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] != 0) continue;
        dijkstra(grid, i, j);
      }
    }
  }
};

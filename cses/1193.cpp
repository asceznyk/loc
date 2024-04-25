#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#include <queue>

using namespace std;

void dijkstra(
  vector<vector<char>>& grid, vector<vector<int>>& dist, vector<vector<int>>& visited,
  int i, int j
) {
  int ispath = 0;
  dist[i][j] = 0;
  priority_queue<pair<int, vector<int>>> pq;
  pq.push({0, {i, j}});
  unordered_map<char, vector<int>> dirs;
  dirs['L'] = {0,-1};
  dirs['U'] = {-1,0};
  dirs['R'] = {0,1};
  dirs['D'] = {1,0};
  int x = i, y = j;
  while(!pq.empty()) {
    vector<int> coords = pq.top().second; pq.pop();
    i = coords[0], j = coords[1];
    if(grid[i][j] == 'B') {
      x = i, y = j;
      ispath = 1;
    };
    for(auto d: dirs) {
      int di = i+d.second[0], dj = j+d.second[1];
      if (
        di > (int)grid.size()-1 || di < 0 || dj > (int)grid[0].size()-1 || dj < 0 ||
        visited[di][dj] != 0 || grid[di][dj] == '#'
      ) continue;
      if (1+dist[i][j] < dist[di][dj]) {
        visited[di][dj] = 1;
        dist[di][dj] = 1+dist[i][j];
        pq.push({-dist[di][dj], {di, dj}});
      }
    }
  }
  if(!ispath) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << dist[x][y] << "\n";
  vector<char> lurd;
  unordered_map<char, char> opp;
  opp['L'] = 'R';
  opp['U'] = 'D';
  opp['R'] = 'L';
  opp['D'] = 'U';
  while (grid[x][y] != 'A') {
    char minChar;
    vector<int> nearest = {-1,-1};
    for(auto d: dirs) {
      int dx = x+d.second[0], dy= y+d.second[1];
      if (
        dx > (int)grid.size()-1 || dx < 0 || dy > (int)grid[0].size()-1 || dy < 0 
      ) continue;
      if(dist[dx][dy] < dist[x][y]) {
        nearest = {dx, dy};
        minChar = opp[d.first];
      }
    }
    x = nearest[0], y = nearest[1];
    lurd.push_back(minChar);
  }
  for(int i = (int)lurd.size()-1; i > -1; i--) cout << lurd[i];
  cout << '\n';
}

int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  vector<vector<int>> visited(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] != 'A') continue;
      dijkstra(grid, dist, visited, i, j);
      return 0;
    }
  }
}



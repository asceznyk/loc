class Solution {
public:
  vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
  void dfs(
    int i, int j, int id,
    vector<vector<int>>& grid,
    unordered_map<int,int>& areaId
  ) {
    int n = grid.size();
    grid[i][j] = id;
    areaId[id]++;
    for (auto& dir: dirs) {
      int di = i+dir[0], dj = j+dir[1];
      if (
        di < 0 || di > n-1 || dj < 0 || dj > n-1 ||
        grid[di][dj] != 1 || grid[di][dj] == 0
      ) continue;
      dfs(di, dj, id, grid, areaId);
    }
  }
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int,int> areaId;
    int id = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 || grid[i][j] != 1) continue;
        dfs(i, j, id, grid, areaId);
        id++;
      }
    }
    int ans = areaId[2];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) continue;
        int area = 1;
        unordered_map<int,bool> visitedIDs;
        for(auto& dir: dirs) {
          int di = i+dir[0], dj = j+dir[1];
          if(di < 0 || di > n-1 || dj < 0 || dj > n-1 || grid[di][dj] == 0)
            continue;
          int id = grid[di][dj];
          if (visitedIDs[id]) continue;
          visitedIDs[id] = true;
          area += areaId[id];
        }
        ans = max(area, ans);
      }
    }
    return ans;
  }
};



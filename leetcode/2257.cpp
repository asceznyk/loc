class Solution {
public:
  vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
  int countUnguarded(
    int m, int n,
    vector<vector<int>>& guards, vector<vector<int>>& walls
  ) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (vector<int>& wall: walls) {
      int i = wall[0], j = wall[1];
      grid[i][j] = 1;
    }
    for (vector<int>& guard: guards) {
      int i = guard[0], j = guard[1];
      grid[i][j] = 2;
    }
    for (vector<int>& guard: guards) {
      int i = guard[0], j = guard[1];
      for (vector<int>& dir: dirs) {
        int x = i, y = j;
        while (true) {
          x += dir[0], y += dir[1];
          if (
            x < 0 || x > m-1 || y < 0 || y > n-1 ||
            grid[x][y] == 1 || grid[x][y] == 2
          ) break;
          if (grid[x][y] == 3) continue;
          grid[x][y] = 3;
        }
      }
    }
    int ans = 0;
    for (vector<int>& row: grid) {
      for (int val: row) {
        if (val != 0) continue;
        ans++;
      }
    }
    return ans;
  }
};


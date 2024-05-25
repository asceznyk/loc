class Solution {
private:
  void dfs(
    vector<vector<int>>& heights, vector<vector<int>>& dirs,
    vector<vector<vector<int>>>& visted, int i, int j, int m, int n, int from 
  ) {
    visted[i][j][from] = 1;
    for(int x = 0; x < dirs.size(); x++) {
      int di = i+dirs[x][0], dj = j+dirs[x][1];
      if (
        di < 0 || di > m-1 || dj < 0 || dj > n-1 || 
        visted[di][dj][from] || heights[i][j] > heights[di][dj]  
      ) continue;
      dfs(heights, dirs, visted, di, dj, m, n, from);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<int> count = {0};
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> marked;
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<vector<int>>> visted(m, vector<vector<int>>(n, vector<int>(2,0)));
    for(int i = 1; i < m; i++) { 
      visted[i][0] = {1,0};
      visted[i][n-1] = {0,1};
    }
    for(int j = 1; j < n; j++) { 
      visted[0][j] = {1,0};
      visted[m-1][j] = {0,1};
    }
    visted[0][n-1] = {1,1};
    visted[m-1][0] = {1,1};
    for(int i = 0; i < m; i++) {
      dfs(heights, dirs, visted, i, 0, m, n, 0);
      dfs(heights, dirs, visted, i, n-1, m, n, 1);
    }
    for(int j = 0; j < n; j++) {
      dfs(heights, dirs, visted, 0, j, m, n, 0);
      dfs(heights, dirs, visted, m-1, j, m, n, 1);
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(visted[i][j][0] && visted[i][j][1]) marked.push_back({i,j});
      }
    }
    return marked;
  }
};

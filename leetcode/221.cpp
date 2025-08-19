class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> conHeights(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
      int height = 0;
      for (int i = 0; i < m; i++) {
        int curr = matrix[i][j] - '0';
        if (curr == 1) height++;
        else height = 0;
        conHeights[i][j] = height;
      }
    }
    int ans = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int height = conHeights[i][j];
        int l = j;
        while (l > -1 && conHeights[i][l] >= height) l--;
        int r = j;
        while (r < n && conHeights[i][r] >= height) r++;
        l++;
        r--;
        if (r < 0 || r > n || l < 0 || l > n || r-l+1 < height) continue;
        ans = max(ans, height*height);
      }
    }
    return ans;
  }
};


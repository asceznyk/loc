class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> maxSide(m, vector<int>(n, 0));
    vector<int> sCnt(max(m,n)+1, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          maxSide[i][j] = matrix[i][j];
          continue;
        }
        if (matrix[i][j] == 0) continue;
        maxSide[i][j] = 1 + min(min(maxSide[i-1][j], maxSide[i-1][j-1]), maxSide[i][j-1]);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        sCnt[maxSide[i][j]]++;
      }
    }
    sCnt[0] = 0;
    vector<int> suffix(sCnt.size(), 0);
    int s = 0, ans = 0;
    for (int i = sCnt.size()-1; i > 0; i--) {
      s += sCnt[i];
      suffix[i] += s;
      ans += suffix[i];
    }
    return ans;
  }
};


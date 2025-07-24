class Solution {
public:
  int dfs(
    int i, int r, int h,
    vector<vector<int>>& books, int shelfWidth,
    vector<vector<int>>& memo
  ) {
    if (i == (int)books.size()) return h;
    if (memo[i][r] != 0) return memo[i][r];
    vector<int> curr = books[i];
    int opt1 = h + dfs(i+1, shelfWidth-curr[0], curr[1], books, shelfWidth, memo);
    int opt2 = INT_MAX;
    if (r >= curr[0]) {
      opt2 = dfs(i+1, r-curr[0], max(h,curr[1]), books, shelfWidth, memo);
    }
    return memo[i][r] = min(opt1, opt2);
  }
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int ans = 0;
    int n = books.size();
    vector<vector<int>> memo(n, vector<int>(shelfWidth+1, 0));
    return dfs(0, shelfWidth, 0, books, shelfWidth, memo);
  }
};

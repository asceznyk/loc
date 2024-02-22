class Solution {
private:
  void dfs(
    vector<vector<char>>& board, 
    vector<vector<bool>>& visted,
    int i, int j, int m, int n
  ) {
    if(
      i < 0 || i > m-1 || j < 0 || j > n-1 || board[i][j] == 'X' || visted[i][j]
    ) return;
    visted[i][j] = true;
    dfs(board, visted, i+1, j, m, n);
    dfs(board, visted, i-1, j, m, n); 
    dfs(board, visted, i, j+1, m, n);
    dfs(board, visted, i, j-1, m, n);
  };
public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    if(m == 1 && n == 1) return;
    vector<vector<bool>> visted(m, vector<bool>(n, 0));
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] == 'X' || visted[i][j]) continue;
        if(i == 0 || i == m-1 || j == 0 || j == n-1) dfs(board, visted, i, j, m, n);
      }
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(!visted[i][j] && board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};

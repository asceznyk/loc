class Solution {
public:
  bool isValid(vector<vector<char>>& board, int i, int j, char e) {
    for (int k = 0; k < 9; k++) {
      if (board[k][j] == e ||
          board[i][k] == e || 
          board[(3*(i/3))+k/3][(3*(j/3))+k%3] == e) return false;
    }
    return true;
  }
  bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if(board[i][j] == '.') {
          for (char x = '1'; x <= '9'; x++) {
            if (isValid(board, i, j, x)) {
              board[i][j] = x;
              if (solve(board)) return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>>& board) {
    solve(board);
  }
};


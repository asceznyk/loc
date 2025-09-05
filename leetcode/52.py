class Solution:
  cnt = 0
  def solveNQueens(self, n:int) -> int:
    self.cnt = 0
    def backtrack(i:int):
      if i == n:
        self.cnt += 1
        return
      for j in range(n):
        if columns[j] or diag1[i+j] or diag2[j-i+n-1]: continue
        board[i][j] = "Q"
        columns[j] = diag1[i+j] = diag2[j-i+n-1] = 1
        backtrack(i+1)
        columns[j] = diag1[i+j] = diag2[j-i+n-1] = 0
        board[i][j] = "."
    board = [["." for _ in range(n)] for _ in range(n)]
    columns = [0 for _ in range(n)]
    diag1 = [0 for _ in range(2*n-1)]
    diag2 = [0 for _ in range(2*n-1)]
    backtrack(0)
    return self.cnt


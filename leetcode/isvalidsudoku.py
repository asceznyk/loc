from typing import List


class Solution:

  def isValidArr(self, arr:List[str]) -> bool:
    arr = sorted(arr)
    p = "-"
    for k in arr:
      if (k == p) and (p != "."): return False
      p = k
    return True

  def isValidSudoku(self, board:List[List[str]]) -> bool:
    roff, coff = 0, 0
    for i in range(len(board)):
      if not self.isValidArr(board[i]): return False
      if not self.isValidArr([row[i] for row in board]): return False
      box = []
      [[box.append([r+roff,c+coff]) for c in range(3)] for r in range(3)]
      cells = [board[y][x] for [y,x] in box]
      if not self.isValidArr(cells): return False
      if not (i+1)%3: roff += 3
      coff = 3 * ((i+1)%3)
    return True


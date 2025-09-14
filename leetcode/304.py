class NumMatrix:
    def __init__(self, matrix:List[List[int]]):
      m, n = len(matrix), len(matrix[0])
      self.prefixRow = [[0 for _ in range(n)] for _ in range(m)]
      for i, row in enumerate(matrix):
        p = 0 
        for j, v in enumerate(row):
          p += v
          self.prefixRow[i][j] = p
    def sumRegion(self, row1:int, col1:int, row2:int, col2:int) -> int:
      s = 0
      for x in range(row1, row2+1):
        s += self.prefixRow[x][col2] - \
          (self.prefixRow[x][col1-1] if col1 > 0 else 0)
      return s 




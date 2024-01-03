from typing import List

class Solution:

  def search(self, nums:List[int], target:int) -> int:
    lp = 0
    rp = len(nums)-1
    while lp <= rp:
      mp = (rp+lp)//2
      n = nums[mp]
      if n == target: return True
      if n < target: lp = mp+1
      elif n > target: rp = mp-1
    return False

  def searchMatrix(self, matrix:List[List[int]], target:int) -> bool:
    for row in matrix:
      if self.search(row, target): return True
    for i in range(len(matrix[0])):
      if self.search([row[i] for row in matrix], target): return True
    return False

class Solution:
  def searchMatrix(self, matrix:List[List[int]], target:int) -> bool:
    rows, cols = len(matrix), len(matrix[0])
    r, c = 0, cols-1
    while r < rows and c > -1:
      curr = matrix[r][c]
      if curr == target: return True
      if curr < target: r += 1
      else: c -= 1
    return False


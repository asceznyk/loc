class Solution:
  def generate(self, numRows:int) -> List[List[int]]:
    pascal = [[1],[1,1]]
    if numRows <= 2: 
      return pascal[:numRows]
    for i in range(3, numRows+1):
      row = [1 for _ in range(i)]
      for j in range(1, i-1):
        row[j] = pascal[i-2][j-1] + pascal[i-2][j]
      pascal.append(row)
    return pascal


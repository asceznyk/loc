MOD = (10**9) + 7

class Solution:
  def knightDialer(self, n:int) -> int:
    moves = [
      [4,6],
      [6,8],
      [7,9],
      [4,8],
      [0,3,9],
      [],
      [0,1,7],
      [2,6],
      [1,3],
      [2,4]
    ]
    @cache
    def dfs(sq:int, m:int) -> int:
      if m == n:
        return 1
      count = 0
      for digit in moves[sq]:
        count += dfs(digit, m+1)
      return count
    ans = 0
    dp = {}
    for i in range(len(moves)): 
      ans += dfs(i, 1) 
    return ans % MOD 



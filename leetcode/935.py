MOD = (10**9) + 7

class Solution:
  def knightDialer(self, n:int) -> int:
    moves = [
      "4,6",
      "6,8",
      "7,9",
      "4,8",
      "0,3,9",
      "",
      "0,1,7",
      "2,6",
      "1,3",
      "2,4"
    ]
    def dfs(seq:str) -> int:
      m = len(seq)
      sq = seq[-1]
      mark = (sq,n-m)
      if mark in dp:
        return dp[mark]
      if m == n:
        dp[mark] = 1
        return dp[mark]
      if seq[-1] == "5":
        return 0
      count = 0
      for digit in moves[int(sq)].split(","):
        count += dfs(seq+digit) 
      dp[mark] = count 
      return dp[mark] 
    ans = 0
    dp = {}
    for i in range(len(moves)): 
      ans += dfs(str(i)) 
    return ans % MOD



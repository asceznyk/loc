class Solution:
  INF = (10**9) + 7
  def maximumValueSum(self, nums:List[int], k:int, edges:List[List[int]]) -> int:
    def dfs(i:int, b:int) -> int:
      if i == n:
        return 0 if b == 1 else -self.INF+5
      if mem[i][b] != -self.INF: return mem[i][b]
      mem[i][b] = max(
        nums[i] + dfs(i+1, b),
        (nums[i]^k) + dfs(i+1, b^1)
      )
      return mem[i][b]
    n = len(nums)
    mem = [[-self.INF, -self.INF] for i in range(n)]
    return dfs(0,1)


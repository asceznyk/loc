from utils import *

class Solution:
  def minKBitFlips(self, nums:List[int], k:int) -> int:
    print(f"nums = {nums}, k = {k}")
    n = len(nums)
    if k == 1:
      return n - sum(nums) 
    i, j, cnt, nxt = 0, 0, 0, 0
    while i < n-k+1:
      if nums[i] == nxt and i < j+k:
        cnt += 1
        nxt ^= 1
        j = i
        i += 1
        continue
      elif i == j+k:
        nxt = 0
        j = i 
      else:
        i += 1
    print(f"j = {j}, nxt = {nxt}, cnt = {cnt}, isit = {j+k-1 == n-1}?")
    # or :
    #  print(f"cnt = {cnt}")
    #else:
    #  print("-1")
    return cnt

if __name__ == "__main__":
  sol = Solution()
  sol.minKBitFlips([0,1,0], 1)
  sol.minKBitFlips([1,1,0], 2)
  sol.minKBitFlips([0,0,0,1,0,1,1,0], 3)
  sol.minKBitFlips([1,0,1,1], 3)
  sol.minKBitFlips([1,1,0,0], 2)
  sol.minKBitFlips([0,0,1,1,0,1,0,0,0], 4)


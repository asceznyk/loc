from utils import *

class Solution:
  def minKBitFlips(self, nums:List[int], k:int) -> int:
    n = len(nums)
    i, c = 0, 0
    for i in range(n-k+1):
      if nums[i] == 0:
        c += 1
        for j in range (i, i+k):
          nums[j] ^= 1
    print(f"c = {c}, nums = {nums}")
    return -1 if sum(nums) < n else c

if __name__ == "__main__":
  sol = Solution()
  sol.minKBitFlips([0,0,0,1,0,1,1,0], 3)
  sol.minKBitFlips([1,1,0], 2)
  sol.minKBitFlips([0,1,0], 1)


class Solution:
  def minOperations(self, nums:List[int]) -> int:
    n = len(nums)
    i, c = 0, 0
    while i < n-2:
      if nums[i] == 0:
        c += 1
        nums[i] ^= 1
        nums[i+1] ^= 1
        nums[i+2] ^= 1
      i += 1
    return -1 if sum(nums) < n else c


class Solution:

  def maxSubarraySum(self, nums:List[int], smax:bool=False) -> Tuple[int,int]:
    s, m = 0, nums[0] 
    if smax:
      s = 0
      for x in nums:
        s = max(x+s, x)
        m = max(m, s)
      return m
    else:
      s, m = 10**9 + 5, 10**9 + 5
      for x in nums:
        s = min(x+s, x)
        m = min(m, s)
      return m 


  def maxSubarraySumCircular(self, nums:List[int]) -> int:
    fullsum = sum(nums)
    maxsum = self.maxSubarraySum(nums, smax=True)
    minsum = self.maxSubarraySum(nums)
    if minsum == fullsum:
      return maxsum
    return max(maxsum, fullsum-minsum)


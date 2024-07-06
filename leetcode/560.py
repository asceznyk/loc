class Solution:
  def subarraySum(self, nums:List[int], k:int) -> int:
    t, s = 0, 0
    sPrefix = {0: 1}
    for i in range(len(nums)):
      s += nums[i]
      t += sPrefix.get(s-k, 0)
      if not sPrefix.get(s): sPrefix[s] = 1
      else: sPrefix[s] += 1
    return t

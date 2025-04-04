class Solution:
  def countFairPairs(self, nums:List[int], lower:int, upper:int) -> int:
    nums.sort()
    n = len(nums)
    if n == 1: return 0
    ans = 0
    def lowerBound(nums:List[int], start:int, target:int) -> int:
      left, right = start+1, len(nums) - 1
      while left <= right:
        mid = (left + right) // 2
        if nums[start]+nums[mid] < target:
          left = mid + 1
        else:
          right = mid - 1
      return left
    def upperBound(nums:List[int], start:int, target:int) -> int:
      left, right = start+1, len(nums) - 1
      while left <= right:
        mid = (left + right) // 2
        if nums[start]+nums[mid] <= target:
          left = mid + 1 
        else:
          right = mid - 1 
      return right
    for i, x in enumerate(nums):
      lb = lowerBound(nums, i, lower)
      ub = upperBound(nums, i, upper)
      if lb <= ub: ans += (ub-lb)+1
    return ans


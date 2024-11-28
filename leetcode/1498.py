class Solution:
  def numSubseq(self, nums:List[int], target:int) -> int:
    def count(nums:List[int], target:int, l:int, r:int, sign:int) -> int:
      if r-l < 0: return 0
      if sign == 1:
        x = -1
        b = r
        while b >= 1:
          while x+b <= r and nums[l] + nums[x+b] <= target: x += b
          b = b//2
        r = x
      else:
        x = -1
        b = r
        while b >= 1:
          while x+b <= r and nums[x+b] + nums[r] <= target: x += b
          b = b//2
        l = x+1
      if r-l == 0:
        return sign*int(2*nums[l] <= target) if sign == 1 else sign*int(2*nums[l] > target)
      return sign*((2**(r-l+1))-1) + count(nums, target, l, r, -1*sign)
    nums.sort()
    return count(nums, target, 0, len(nums)-1, 1) % ((10**9)+7)


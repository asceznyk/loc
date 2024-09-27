class Solution:
  def checkPossibility(self, nums:List[int]) -> bool:
    once = False
    for i in range(1, len(nums)):
      p, x = nums[i-1], nums[i]
      if p > x and once:
        return False
      if p > x:
        nums[i-1] = x
        if (nums[i-2] if i-2 >= 0 else 0) > nums[i-1]:
          nums[i-1] = p
          nums[i] = p
        once = True
    return True


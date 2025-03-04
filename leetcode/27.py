class Solution:
  def removeElement(self, nums:List[int], val:int) -> int:
    print(nums, val)
    n = len(nums)
    nums.sort()
    if val > 50:
      return n
    start, end = -1, -1
    for i, x in enumerate(nums):
      if x == val:
        if start == -1: start = i
        end = i
    cop = nums[0:start] + nums[end+1:] if start != -1 else nums
    for i, x in enumerate(cop): nums[i] = cop[i]
    return len(cop)



from typing import List

class Solution:
  def checkPossibility(self, nums:List[int]) -> bool:
    once = False
    for i in range(1, len(nums)):
      p, x = nums[i-1], nums[i]
      if p > x and once:
        print("False")
        return False
      if p > x:
        nums[i-1] = x
        if (nums[i-2] if i-2 >= 0 else 0) > nums[i-1]:
          nums[i-1] = p
          nums[i] = p
        once = True
    print(nums)
    print("True")
    return True

if __name__ == "__main__":
  solve = Solution()
  solve.checkPossibility([4,2,3])
  solve.checkPossibility([4,2,1])
  solve.checkPossibility([3,4,2,3])
  solve.checkPossibility([5,7,1,8])
  solve.checkPossibility([2,4,2,3])


class Solution:
  def fourSum(self, nums:List[int], target:int) -> List[List[int]]:
    nums.sort()
    n = len(nums)
    res = set()
    for i in range(n):
      for j in range(i+1, n):
        l, r = j+1, n-1
        a, b = nums[i], nums[j]
        local = target-(a+b)
        while l < r:
          c,d = nums[l],nums[r]
          if c+d == local: 
            res.add((a,b,c,d))
            l += 1
            r -= 1
          elif c+d < local:
            l += 1
          else:
            r -= 1
    return list([list(x) for x in res])


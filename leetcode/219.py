class Solution:
  def containsNearbyDuplicate(self, nums:List[int], k:int) -> bool:
    if k == 0:
      return False
    lkey = {}
    for j, x in enumerate(nums):
      if lkey.get(x, -1) == -1:
        lkey[x] = j
        continue
      i = lkey[x]
      if x == nums[i] and abs(i-j) <= k:
        return True
      lkey[x] = j
    return False



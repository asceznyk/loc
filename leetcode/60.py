class Solution:

  def buildPermutations(self, nums:List[int], n:int, s:str):
    if len(s) == n:
      self.perms.append(s)
      return
    for x in nums:
      if x in s: continue
      self.buildPermutations(nums, n, s+x)
    return

  def getPermutation(self, n:int, k:int) -> str:
    self.perms = []
    nums = [str(i) for i in range(1, n+1)]
    self.buildPermutations(nums, n, "")
    return perms[k-1]


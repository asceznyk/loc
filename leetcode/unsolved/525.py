from utils import *

class Solution:
  def findMaxLength(self, nums:List[int]) -> int:
    print(f"len(nums) = {len(nums)}")
    zMap = [0,0]
    cMap = [0,0]
    for i,x in enumerate(nums):
      if zMap[0] < zMap[1]:
        ans = max(ans, 2*zMap[0])
      elif zMap[1] < zMap[0]:
        ans = max(ans, 2*zMap[1])
      else:
        ans = max(ans, i+1)
      print(f"i = {i}, zMap = {zMap}, ans = {ans}")
    return ans

if __name__ == "__main__":
  sol = Solution()
  sol.findMaxLength([1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1])

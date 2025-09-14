class Solution:
  def kthLargestNumber(self, nums:List[str], k:int) -> str:
    ans = str(sorted([int(x) for x in nums], reverse=True)[k-1])
    return ans


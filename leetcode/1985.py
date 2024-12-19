from typing import List

class Solution:
  def kthLargestNumber(self, nums:List[str], k:int) -> str:
    ans = str(sorted([int(x) for x in nums], reverse=True)[k-1])
    print(ans)
    return ans

if __name__ == "__main__":
  sol = Solution()
  sol.kthLargestNumber(["3","6","7","10"], 4)
  sol.kthLargestNumber(["2","21","12","1"], 3)
  sol.kthLargestNumber(["0","0"], 2)


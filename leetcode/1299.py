from typing import List

class Solution:
  def replaceElements(self, arr:List[int]) -> List[int]:
    mstack = sorted([(x, i) for i, x in enumerate(arr[1:])])
    res = []
    for i in range(len(arr)-1):
      while i > mstack[-1][1]:
        mstack.pop()
      res.append(mstack[-1][0])
    res.append(-1)
    return res

if __name__ == "__main__":
  sol = Solution()
  sol.replaceElements([17,18,5,4,6,1])
  sol.replaceElements([400])


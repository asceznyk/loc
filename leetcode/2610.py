class Solution:
  def findMatrix(self, nums:List[int]) -> List[List[int]]:
    nums.sort()
    p, i = 0, 0
    res = [[]]
    for x in nums:
      if p == x:
        if i == len(res)-1:
          res.append([x])
        else:
          res[i+1].append(x)
        i += 1
      else:
        i = 0
        res[i].append(x)
      p = x
    return res



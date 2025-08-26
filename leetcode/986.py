class Solution:
  def intervalIntersection(
    self, firstList:List[List[int]], secondList:List[List[int]]
  ) -> List[List[int]]:
    m, n = len(firstList), len(secondList)
    if m == 0 or n == 0: return []
    res = []
    for i in range(m):
      inter1 = firstList[i]
      for j in range(n):
        inter2 = secondList[j]
        if inter2[0] > inter1[1] or inter1[0] > inter2[1]: continue
        if inter2[1] <= inter1[0] or inter1[1] >= inter2[0]:
          res.append([max(inter1[0], inter2[0]), min(inter1[1], inter2[1])])
    return res



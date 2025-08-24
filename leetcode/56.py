class Solution:
  def merge(self, intervals:List[List[int]]) -> List[List[int]]:
    intervals = sorted(intervals, key=lambda x: x[0])
    res = []
    union = intervals[0]
    for i in range(1, len(intervals)):
      inter = intervals[i]
      if union[1] >= inter[0]:
        union = [min(union[0],inter[0]), max(union[1],inter[1])]
        continue
      res.append(union)
      union = inter
    res.append(union)
    return res


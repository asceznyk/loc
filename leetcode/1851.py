class Solution:
  def minInterval(self, intervals:List[List[int]], queries:List[int]) -> List[int]:
    intervals.sort()
    queries = sorted([(q,i) for i,q in enumerate(queries)])
    minHeap = []
    inter = [(-1, -1) for _ in range(len(queries))]
    i = 0
    for k, (q, j) in enumerate(queries):
      while minHeap and q > minHeap[0][2]: heappop(minHeap)
      while i < len(intervals) and q >= intervals[i][0]:
        [start, end] = intervals[i]
        if start <= q <= end:
          heappush(
            minHeap,
            (end-start+1, start, end)
          )
        i += 1
      while minHeap and (q > minHeap[0][2] or q < minHeap[0][1]):
        heappop(minHeap)
      inter[k] = (-1 if not len(minHeap) else minHeap[0][0], j)
    res = [-1 for _ in range(len(queries))]
    for s, i in inter: res[i] = s
    return res


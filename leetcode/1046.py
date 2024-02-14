import heapq
from typing import List

class Solution:
  def lastStoneWeight(self, stones:List[int]) -> int:
    heap = [-i for i in stones]
    heapq.heapify(heap)
    while len(heap) > 1:
      y, x = -heapq.heappop(heap), -heapq.heappop(heap)
      heapq.heappush(heap, -(y-x))
    return -heap[0]

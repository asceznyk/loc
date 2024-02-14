import heapq
from typing import List

class Solution:
  def findKthLargest(self, nums:List[int], k:int) -> int:
    heap = nums[:k].copy()
    heapq.heapify(heap)
    for i in range(k, len(nums)):
      heapq.heappush(heap, nums[i])
      if len(heap) > k: heapq.heappop(heap)
    return heap[0]



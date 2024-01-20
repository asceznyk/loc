import heapq

from typing import List

class Solution:
  def findKthLargest(self, nums:List[int], k:int) -> int:
    heap = nums[:k].copy()
    heapq.heapify(heap)
    for i in range(k, len(nums)):
      if nums[i] <= heap[0]: continue
      heapq.heappop(heap)
      heapq.heappush(heap, nums[i])
    return heap[0]



class Solution:
  def maxSlidingWindow(self, nums:List[int], k:int) -> List[int]:
    n = len(nums)
    win = [(-x,i) for i,x in enumerate(nums[:k])]
    heapq.heapify(win)
    res = [-win[0][0]]
    for i in range(k, n):
      x = nums[i]
      j = win[0][1]
      while i+1-k > j:
        heapq.heappop(win)
        if not len(win): break 
        j = win[0][1]
      heapq.heappush(win, (-x, i))
      res.append(-win[0][0])
    return res


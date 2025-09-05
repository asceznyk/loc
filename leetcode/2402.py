class Solution:
  def mostBooked(self, n:int, meetings:List[List[int]]) -> int:
    m = len(meetings)
    meetings.sort(key=lambda x: x[0])
    endHeap = [(meetings[0][1], 0)]
    roomHeap = [i for i in range(1,n)]
    roomCnt = [0 for _ in range(n)]
    roomCnt[0] = 1
    for i in range(1, m):
      [start, end] = meetings[i]
      if len(endHeap) == n and start < endHeap[0][0]:
        pend, rid = heappop(endHeap)
        heappush(endHeap, (pend+(end-start), rid))
        roomCnt[rid] += 1
      while len(endHeap) and start >= endHeap[0][0]:
        (_, rid) = heappop(endHeap)
        heappush(roomHeap, rid)
      if len(roomHeap):
        rid = heappop(roomHeap)
        roomCnt[rid] += 1
        heappush(endHeap, (end, rid))
    maxCnt, ans = 0, -1
    for i, cnt in enumerate(roomCnt):
      if cnt > maxCnt:
        maxCnt = cnt
        ans = i
    return ans


class Solution:
  def findAllPeople(self, n:int, meetings:List[List[int]], firstPerson:int) -> List[int]:
    adj = [[] for _ in range(n)]
    for a, b, t in meetings:
      adj[a].append((b,t))
      adj[b].append((a,t))
    visited = [0 for _ in range(n)]
    minHeap = []
    heappush(minHeap, (0, 0))
    heappush(minHeap, (0, firstPerson))
    while len(minHeap):
      p, x = heappop(minHeap)
      if visited[x]: continue
      visited[x] = 1
      for (y, q) in adj[x]:
        if p > q or visited[y]: continue
        if x == 0 and y == firstPerson or y == 0 and x == firstPerson:
          heappush(minHeap, (0,y))
        else: heappush(minHeap, (q,y))
    return [i for i,v in enumerate(visited) if v == 1]


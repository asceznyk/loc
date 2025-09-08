class Solution:
  def secondMinimum(
    self, n:int, edges:List[List[int]], time:int, change:int
  ) -> int:
    adj = defaultdict(list)
    for edge in edges:
      [u,v] = edge
      adj[u].append(v)
      adj[v].append(u)
    time1 = [-1]*(n+1)
    time2 = [-1]*(n+1)
    queue = deque([(1,1)])
    time1[1] = 0
    while len(queue):
      u, f = queue.popleft()
      timeTaken = time1[u] if f == 1 else time2[u]
      if (timeTaken//change) % 2 == 1:
        timeTaken = change * (timeTaken // change + 1) + time
      else: timeTaken = timeTaken + time
      for v in adj[u]:
        if time1[v] == -1:
          time1[v] = timeTaken
          queue.append((v, 1))
        elif time2[v] == -1 and time1[v] != timeTaken:
          if v == n: return timeTaken
          time2[v] = timeTaken
          queue.append((v, 2))
    return 0


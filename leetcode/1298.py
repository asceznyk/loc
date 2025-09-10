class Solution:
  accessible, status = [], []
  def bfs(self, box:int, keys:List[List[int]], containedBoxes:List[List[int]]):
    queue = deque([box])
    while len(queue):
      box = queue.popleft()
      self.accessible[box] = 1
      if not self.status[box]: continue
      for key in keys[box]:
        if self.status[key]: continue
        self.status[key] = 1
        if self.accessible[key]: queue.append(key)
      for nextBox in containedBoxes[box]: queue.append(nextBox)
  def maxCandies(
    self,
    status:List[int],
    candies:List[int],
    keys:List[List[int]],
    containedBoxes:List[List[int]],
    initialBoxes:List[int]
  ) -> int:
    ans = 0
    self.accessible = [0 for _ in range(len(status))]
    self.status = status
    for box in initialBoxes:
      self.accessible[box] = 1
      if not self.status[box]: continue
      self.bfs(box, keys, containedBoxes)
      for key in keys[box]:
        if self.status[key]: continue
        self.status[key] = 1
    for box in range(len(self.status)):
      if self.status[box] and self.accessible[box]:
        ans += candies[box]
    return ans


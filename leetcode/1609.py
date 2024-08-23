class Solution:
  def isEvenOddTree(self, root:Optional[TreeNode]) -> List[List[int]]:
    visited = []
    queue = deque([root])
    while queue:
      level = []
      for _ in range(len(queue)):
        node = queue.popleft()
        if not node: continue
        level.append(node.val)
        queue.append(node.left)
        queue.append(node.right)
      if level: visited.append(level)
    for i, level in enumerate(visited):
      if (i % 2):
        p = 10**6+5
        for v in level:
          if (v % 2) or v >= p: return False
          p = v
      else:
        p = 0
        for v in level:
          if not (v % 2) or p >= v: return False
          p = v
    return True

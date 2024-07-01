class Solution:
  def zigzagLevelOrder(self, root:Optional[TreeNode]) -> List[List[int]]:
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
    zigzag = []
    for i in range(len(visited)):
      level = visited[i].copy()
      if (i%2): zigzag.append(list(reversed(level)))
      else: zigzag.append(level)
    return zigzag 


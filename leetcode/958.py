class Solution:
  def isCompleteTree(self, root:Optional[TreeNode]) -> bool:
    visited = []
    queue = deque([root])
    while queue:
      level = []
      for _ in range(len(queue)):
        node = queue.popleft()
        if not node:
          level.append(0)
          continue
        level.append(node.val)
        queue.append(node.left)
        queue.append(node.right)
      if sum(level) > 0: visited.append(level)
    p = -1
    for l in visited:
      for c in l:
        if c > 0 and p == 0: return False
        p = c
    return True



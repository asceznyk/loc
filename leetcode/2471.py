class Solution:
  def minimumOperations(self, root:Optional[TreeNode]) -> int:
    queue = deque([root])
    levels = []
    while queue:
      level = []
      for _ in range(len(queue)):
        curr = queue.popleft()
        level.append(curr.val)
        if curr.left: queue.append(curr.left)
        if curr.right: queue.append(curr.right)
      levels.append(level)
    swaps = 0
    for level in levels:
      slevel = sorted(level)
      imap = {level[i]:i for i in range(len(level))}
      for i in range(len(level)):
        a, b = level[i], slevel[i]
        if a == b: continue
        level[i] = b
        level[imap[b]] = a
        imap[a], imap[b] = imap[b], imap[b] 
        swaps += 1
    return swaps


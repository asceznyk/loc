class Solution:
  def rightSideView(self, root:TreeNode) -> List[int]:
    res = []
    q = deque()
    if root: q.append(root)
    while q:
      for i in range(len(q)):
        node = q.popleft()
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
        res.append(node.val)
    return res

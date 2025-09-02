class BSTIterator:
  def __init__(self, root:Optional[TreeNode]):
    def dfs(node:Optional[TreeNode]):
      if not node: return
      dfs(node.left)
      self.vals.append(node.val)
      dfs(node.right)
      return
    self.vals = []
    dfs(root)
    self.index = -1
  def next(self) -> int:
    self.index += 1
    return self.vals[self.index]
  def hasNext(self) -> bool:
    return self.index+1 < len(self.val)



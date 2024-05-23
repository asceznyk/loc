class Solution:
  def diameterOfBinaryTree(self, root:TreeNode) -> int:
    def dfs(node:TreeNode, d:int) -> int:
      if not node: return d
      ld = dfs(node.left, d+1)
      rd = dfs(node.right, d+1)
      self.diameter = max(ld+rd-2*(d+1), self.diameter)
      return max(ld, rd)
    self.diameter = 0
    dfs(root, 0)
    return self.diameter

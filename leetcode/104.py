class Solution:
  def maxDepth(self, root:TreeNode) -> int:
    if not root: return 0
    ld = 1+self.maxDepth(root.left)
    rd = 1+self.maxDepth(root.right)
    return max(ld, rd)

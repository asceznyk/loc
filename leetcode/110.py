class Solution:
  def isBalanced(self, root:TreeNode) -> bool:
    def dfs(node:TreeNode, d:int) -> int:
      nonlocal b
      if not node: return d
      ld = dfs(node.left, d+1)
      rd = dfs(node.right, d+1)
      b = (b and (abs(ld - rd) <= 1))
      return max(ld, rd)
    b = True
    r = dfs(root, 0)
    return b

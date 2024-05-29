class Solution:
  def hasPathSum(self, root: Optional[TreeNode], targetSum:int) -> bool:
    def dfs(node:TreeNode, s:int) -> bool:
      s += node.val
      r = False
      if node.left: r |= dfs(node.left, s)
      if node.right: r |= dfs(node.right, s)
      if (not node.left) and (not node.right): r = (s == targetSum)
      return r
    return dfs(root, 0) if root else False


class Solution:
  def findBottomLeftValue(self, root:Optional[TreeNode]) -> int:
    val, dmax = 0, -1
    def dfs(node:TreeNode, d:int):
      nonlocal val, dmax
      if not node: return
      if d > dmax:
        dmax = d
        val = node.val
      dfs(node.left, d+1)
      dfs(node.right, d+1)
    dfs(root, 0)
    return val



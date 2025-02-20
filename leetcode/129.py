class Solution:
  def sumNumbers(self, root:Optional[TreeNode]) -> int:
    def dfs(node:TreeNode, s:str) -> int:
      if not node: return 0
      if node.left is None and node.right is None:
        return int(s+str(node.val))
      v = s+str(node.val)
      return int(
        dfs(node.left, v) + \
        dfs(node.right, v)
      )
    return dfs(root, "")


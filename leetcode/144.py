class Solution:
  def preorderTraversal(self, root:TreeNode) -> List[int]:
    def dfs(node:TreeNode):
      if not node: return
      visited.append(node.val)
      dfs(node.left)
      dfs(node.right)
    visited = []
    dfs(root)
    return visited


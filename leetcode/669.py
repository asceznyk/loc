class Solution:
  def trimBST(self, root:Optional[TreeNode], low:int, high:int) -> Optional[TreeNode]: 
    def dfs(node:TreeNode) -> TreeNode:
      if not node: return
      if node.val < low:
        node.left = None
        return dfs(node.right)
      elif node.val > high:
        node.right = None
        return dfs(node.left)
      node.left = dfs(node.left)
      node.right = dfs(node.right)
      return node
    return dfs(root)


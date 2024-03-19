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

class Solution:
  def preorderTraversal(self, root:TreeNode) -> List[int]:
    stack = [root]
    visited = []
    while stack:
      node = stack.pop()
      if not node: continue
      visited.append(node.val)
      stack.append(node.right)
      stack.append(node.left)
    return visited


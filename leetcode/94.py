from typing import List, Union

class Solution:
  def inorderTraversal(self, root:TreeNode) -> List[int]:
    def rdfs(node:TreeNode) -> None:
      if node is None: return
      rdfs(node.left)
      visited.append(node.val)
      rdfs(node.right)
    visited = []
    rdfs(root)
    return visited


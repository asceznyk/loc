from typing import List, Union

class Solution:
  def isValidBST(self, root:TreeNode) -> List[int]:
    def rdfs(node:TreeNode):
      if not node: return
      rdfs(node.left)
      if visited and node.val <= visited[-1]:
        nonlocal isbst
        isbst = False
      visited.append(node.val)
      rdfs(node.right)
    visited = []
    isbst = True
    rdfs(root)
    return isbst


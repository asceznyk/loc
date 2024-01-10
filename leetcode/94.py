from typing import List, Union

## Recursive
class Solution:
  def inorderTraversal(self, root:TreeNode) -> List[int]:
    def rdfs(node:TreeNode):
      if not node: return
      rdfs(node.left)
      visited.append(node.val)
      rdfs(node.right)
    visited = []
    rdfs(root)
    return visited

## Iterative
class Solution:
  def inorderTraversal(self, root:TreeNode) -> List[int]:
    stack = []
    visited = []
    curr = root
    while stack or curr:
      while curr:
        stack.append(curr)
        curr = curr.left
      curr = stack.pop()
      visited.append(curr.val)
      curr = curr.right
    return visited



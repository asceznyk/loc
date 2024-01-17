class Solution:
  def isValidBST(self, root:TreeNode) -> bool:
    stack = []
    visited = []
    curr = root
    while stack or curr:
      while curr:
        stack.append(curr)
        curr = curr.left
      curr = stack.pop()
      if visited and curr.val <= visited[-1]: return False
      visited.append(curr.val)
      curr = curr.right
    return True


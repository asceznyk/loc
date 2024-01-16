class Solution:
  def kthSmallest(self, root:TreeNode, k:int) -> int:
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
    return visited[k-1]


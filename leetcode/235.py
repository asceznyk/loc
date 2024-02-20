from utils import *

class Solution:
  def lowestCommonAncestor(self, root:TreeNode, p:TreeNode, q:TreeNode) -> TreeNode:
    stack = [root]
    while stack:
      node = stack.pop()
      if (p.val < node.val and q.val < node.val): stack.append(node.left)
      elif (p.val > node.val and q.val > node.val): stack.append(node.right)
      else: return node


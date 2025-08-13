class Solution:
  def flipEquiv(self, root1:Optional[TreeNode], root2:Optional[TreeNode]) -> bool:
    def isEqual(node1:Optional[TreeNode], node2:Optional[TreeNode]) -> bool:
      if (node1 is None) and (node2 is None): return True
      if (node1 is None) or (node2 is None) or node1.val != node2.val: return False
      if (node1.left and node2.left and node1.left.val != node2.left.val) or \
          (node1.left is None and node2.right is None) or \
          (node1.right is None and node2.left is None):
        node2.left, node2.right = node2.right, node2.left
      return isEqual(node1.left, node2.left) and isEqual(node1.right, node2.right)
    return isEqual(root1, root2)



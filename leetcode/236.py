class Solution:
  def lowestCommonAncestor(
    self, root:'TreeNode',
    p:'TreeNode', q:'TreeNode'
  ) -> 'TreeNode':
    if not root:
      return None
    if p.val == root.val or q.val == root.val:
      return root
    left = self.lowestCommonAncestor(root.left, p, q)
    right = self.lowestCommonAncestor(root.right, p, q)
    if left and right:
      return root
    return (left or right)


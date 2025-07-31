class Solution:
  def replaceValueInTree(self, root:Optional[TreeNode]) -> Optional[TreeNode]:
    def travel(node:TreeNode, d:int):
      if not node: return
      if len(levelSum) == d: levelSum.append(0)
      levelSum[d] += node.val if d >= 2 else 0
      travel(node.left, d+1)
      travel(node.right, d+1)
    def create(node:TreeNode, alt:TreeNode, d:int):
      if not node: return
      siblingSum = 0
      if node.left is not None: siblingSum += node.left.val
      if node.right is not None: siblingSum += node.right.val
      v = levelSum[d+1]-siblingSum if d+1 >= 2 and d+1 < len(levelSum) else 0
      if node.left is not None: alt.left = TreeNode(v)
      if node.right is not None: alt.right = TreeNode(v)
      create(node.left, alt.left, d+1)
      create(node.right, alt.right, d+1)
    levelSum = []
    travel(root, 0)
    new = TreeNode()
    create(root, new, 0)
    return new 


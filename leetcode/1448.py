class Solution:
  def goodNodes(self, root:TreeNode) -> int:
    count = 0
    def rdfs(node:TreeNode, maxVal:int):
      if not node: return
      if node.val >= maxVal:
        nonlocal count
        maxVal = node.val
        count += 1
      rdfs(node.left, maxVal)
      rdfs(node.right, maxVal)
    rdfs(root,root.val)
    return count

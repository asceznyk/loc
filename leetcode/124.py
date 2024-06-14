class Solution:
  def maxPathSum(self, root:TreeNode) -> int:
    def dfs(node:TreeNode, i:int):
      if not node: return
      dfs(node.left, 2*i+1)
      dfs(node.right, 2*i+2)
      left = nosplit[2*i+1] if nosplit.get(2*i+1, 0) else 0
      right = nosplit[2*i+2] if nosplit.get(2*i+2, 0) else 0
      nosplit[i] = max(node.val, node.val+max(left, right))
      split.append(max(node.val, node.val+left+right))
    nosplit = {}
    split = []
    dfs(root, 0)
    return max(split+list(nosplit.values()))



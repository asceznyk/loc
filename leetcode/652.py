class Solution:
  def findDuplicateSubtrees(self, root:Optional[TreeNode]) -> List[Optional[TreeNode]]:
    def dfs(node:Optional[TreeNode]) -> str:
      if node is None: return ""
      key = f"{node.val}"
      left = dfs(node.left)
      right = dfs(node.right)
      key += f"left_{left}_" if left else ""
      key += "__"
      key += f"right_{right}" if right else ""
      if key in visited:
        ans[key] = node
      else:
        visited[key] = node
      return key
    visited = {}
    ans = {}
    dfs(root)
    return [n for _, n in ans.items()]


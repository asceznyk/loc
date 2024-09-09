class Solution:
  def findDuplicateSubtrees(self, root:Optional[TreeNode]) -> List[Optional[TreeNode]]:
    def proc(node:Optional[TreeNode], d:str):
      if not node: return ""
      res = dfs(node)
      key = f"{node.val}"
      key += "" if not res else f"_{d}_{res}"
      if key in visited:
        ans[key] = node
        return key
      visited[key] = node
      return key
    def dfs(node:Optional[TreeNode]) -> str:
      if node is None: return ""
      return f"{node.val}_{proc(node.left, 'left')}_{proc(node.right, 'left')}"
    visited = {}
    ans = {}
    dfs(root)
    return [n for _, n in ans.items()]


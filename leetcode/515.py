class Solution:
  def largestValues(self, root:TreeNode) -> List[List[int]]:
    def dfs(node:TreeNode, d:int):
      if not node: return
      if len(visited) == d: visited.append(-(2**31)-5)
      visited[d] = max(visited[d], node.val)
      dfs(node.left, d+1)
      dfs(node.right, d+1)
    visited = []
    dfs(root, 0)
    return visited


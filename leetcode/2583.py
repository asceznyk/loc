class Solution:
  def kthLargestLevelSum(self, root:Optional[TreeNode], k:int) -> int:
    def dfs(node:TreeNode, d:int):
      if not node: return
      if len(visited) == d: visited.append(0)
      visited[d] += node.val
      dfs(node.left, d+1)
      dfs(node.right, d+1)
    visited = []
    dfs(root, 0)
    if k > len(visited): return -1
    return sorted(visited, reverse=True)[k-1]
    



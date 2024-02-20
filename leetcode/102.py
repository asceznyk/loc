class Solution:
  def levelOrder(self, root:TreeNode) -> List[List[int]]:
    def rdfs(node:TreeNode, d:int):
      if not node: return
      if len(visited) == d: visited.append([])
      visited[d].append(node.val)
      rdfs(node.left, d+1)
      rdfs(node.right, d+1)
    visited = []
    rdfs(root, 0)
    return visited


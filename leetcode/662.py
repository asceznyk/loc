class Solution:
  def widthOfBinaryTree(self, root:TreeNode) -> int: 
    def rdfs(node:TreeNode, d:int, i:int):
      if not node: return
      if len(visited) == d:
        visited.append([])
      visited[d].append(i)
      rdfs(node.left, d+1, (2*i)+1)
      rdfs(node.right, d+1, (2*i)+2)
    visited = []
    rdfs(root, 0, 0)
    maxDist = 0
    for level in visited:
      maxDist = max(maxDist, (level[-1]-level[0])+1)
    return maxDist



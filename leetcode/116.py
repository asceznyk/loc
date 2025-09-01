class Solution:
  def connect(self, root:'Optional[Node]') -> 'Optional[Node]':
    if not root: return None
    def dfs(node:TreeNode, d:int):
      if not node: return
      if len(visited) == d: visited.append([])
      visited[d].append(node)
      dfs(node.left, d+1)
      dfs(node.right, d+1)
    visited = []
    dfs(root, 0)
    for level in visited:
      node = level[0]
      for right in level[1:]:
        node.next = right
        node = right
    return root


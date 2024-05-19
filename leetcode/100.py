class Solution:
  def isSameTree(self, p:TreeNode, q:TreeNode) -> bool:
    def dfs(node:TreeNode, visted:str):
      if not node:
        visted.append('#')
        return
      visted.append(str(node.val))
      dfs(node.left, visted)
      dfs(node.right, visted)
    pvis = []
    dfs(p, pvis)
    qvis = []
    dfs(q, qvis)
    return ''.join(pvis) == ''.join(qvis)


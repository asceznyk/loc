class Solution:
  def isSubtree(self, root:TreeNode, subRoot:TreeNode) -> bool:
    def dfs(node:TreeNode, visited:List[int]):
      if not node:
        visited.append('#')
        return
      visited.append(str(node.val))
      dfs(node.left, visited)
      dfs(node.right, visited)
    subvis = []
    dfs(subRoot, subvis)
    rvis = []
    dfs(root, rvis)
    ls, lr = len(subvis), len(rvis)
    if lr < ls: return False
    for i in range(lr):
      k = 0
      if rvis[i] != subvis[k]: continue
      while k < ls and rvis[i+k] == subvis[k]: k += 1
      if (k == ls): return True
    return False


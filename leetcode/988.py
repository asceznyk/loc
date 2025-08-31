class Solution:
  res = ""
  def smallestFromLeaf(self, root:Optional[TreeNode]) -> str:
    def dfs(node:Optional[TreeNode], path:str):
      if node.left is not None:
        dfs(node.left, alphabet[node.left.val]+path)
      if node.right is not None:
        dfs(node.right, alphabet[node.right.val]+path)
      if node.left is None and node.right is None \
          and (path < self.res or self.res == ""):
        self.res = path
    self.res = ""
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    dfs(root, alphabet[root.val])
    return self.res


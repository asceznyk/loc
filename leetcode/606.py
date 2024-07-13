class Solution:
  def tree2str(self, root:Optional[TreeNode]) -> str:
    def dfs(node:Optional[TreeNode]):
      if not node: return
      slist.append(str(node.val))
      if node.left is None and node.right is None: return
      for x in [node.left, node.right]:
        if x == node.right and x is None: continue
        slist.append("(")
        dfs(x)
        slist.append(")")
    slist = []
    dfs(root)
    return "".join(slist)


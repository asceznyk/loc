class Solution:
  def insertIntoBST(self, root:Optional[TreeNode], val:int) -> Optional[TreeNode]:
    self.val = val
    def dfs(node):
      if not node: return
      if self.val < node.val: 
        if node.left: dfs(node.left)
        else: node.left = TreeNode(self.val)
      if self.val > node.val:
        if node.right: dfs(node.right)
        else: node.right = TreeNode(self.val)
    dfs(root)
    return TreeNode(self.val) if root is None else root 




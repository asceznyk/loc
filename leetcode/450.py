class Solution:

  def deleteNode(self, root:Optional[TreeNode], key:int) -> Optional[TreeNode]:
    def find(node:TreeNode, key:int):
      if node is None: return 
      if node.val == key:
        return self.delete(copy.deepcopy(node))
      if key > node.val: node.right = find(node.right, key)
      else: node.left = find(node.left, key)
      return node
    return find(root, key)

  def delete(self, found:TreeNode) -> Optional[TreeNode]:
    def farSubtree(node:TreeNode, right:bool=True) -> TreeNode:
      if right: return node if node.right is None else farSubtree(node.right, True)
      return node if node.left is None else farSubtree(node.left, False)
    xroot, xval, cnode = None, None, None
    if found.right:
      xroot = farSubtree(found.right, False)
      xval = xroot.val
      if xroot.right:
        cnode = farSubtree(xroot.right, False) 
        xroot = self.deleteNode(xroot, key=cnode.val)
    elif found.left:
      xroot = farSubtree(found.left)
      xval = xroot.val
      if xroot.left:
        cnode = farSubtree(xroot.left)
        xroot = self.deleteNode(xroot, key=cnode.val)
    else:
      return xroot 
    if cnode is not None: xroot.val = cnode.val
    found = self.deleteNode(found, key=xval)
    found.val = xval
    return found 


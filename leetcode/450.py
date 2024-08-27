import sys
import copy
sys.path.append("../")

from utils import *

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
    xroot, xval, cval = None, None, None
    if found.right:
      xroot = farSubtree(found.right, False)
      xval = xroot.val
      if xroot.right:
        cval = xroot.right.val
        xroot = self.deleteNode(xroot, key=cval)
    elif found.left:
      xroot = farSubtree(found.left)
      xval = xroot.val
      if xroot.left:
        cval = xroot.left.val
        xroot = self.deleteNode(xroot, key=cval)
    else:
      return xroot 
    if cval is not None: xroot.val = cval
    found = self.deleteNode(found, key=xval)
    found.val = xval
    return found 

if __name__ == "__main__":
  solve = Solution()
  solve.deleteNode(buildBinaryTree([5,3,6,2,4,None,7]), key=3)
  solve.deleteNode(buildBinaryTree([5,3,7,2,4,6,8]), key=5)
  solve.deleteNode(buildBinaryTree([5,3,6,2,4,None,7]), key=7)
  solve.deleteNode(buildBinaryTree([]), key=0)
  draw([2,0,33,None,1,25,40,None,None,11,31,34,45,10,18,29,32,None,36,43,46,4,None,12,24,26,30,None,None,35,39,42,44,None,48,3,9,None,14,22,None,None,27,None,None,None,None,38,None,41,None,None,None,47,49,None,None,5,None,13,15,21,23,None,28,37,None,None,None,None,None,None,None,None,8,None,None,None,17,19,None,None,None,None,None,None,None,7,None,16,None,None,20,6])
  draw([2,0,34,None,1,25,40,None,None,11,31,36,45,10,18,29,32,None,37,43,46,4,None,12,24,26,30,None,None,35,39,42,44,None,48,3,9,None,14,22,None,None,27,None,None,None,None,38,None,41,None,None,None,47,49,None,None,5,None,13,15,21,23,None,28,None,None,None,None,None,None,None,None,None,8,None,None,None,17,19,None,None,None,None,None,7,None,16,None,None,20,6])
  draw([2,0,34,None,1,25,40,None,None,11,31,35,45,10,18,29,32,None,36,43,46,4,None,12,24,26,30,None,None,None,39,42,44,None,48,3,9,None,14,22,None,None,27,None,None,38,None,41,None,None,None,47,49,None,None,5,None,13,15,21,23,None,28,37,None,None,None,None,None,None,None,None,8,None,None,None,17,19,None,None,None,None,None,None,None,7,None,16,None,None,20,6])


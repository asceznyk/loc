import sys
import copy
sys.path.append("../")

from utils import *

class Solution:

  def deleteNode(self, root:Optional[TreeNode], key:int) -> Optional[TreeNode]:
    def find(node:TreeNode, key:int):
      if node is None: return 
      if node.val == key:
        if node.right is None and node.left is None: return None
        return self.delete(copy.deepcopy(node))
      if key > node.val: node.right = find(node.right, key)
      else: node.left = find(node.left, key)
      return node
    return find(root, key)

  def delete(self, found:TreeNode) -> Optional[TreeNode]:
    def farSubtree(node:TreeNode, right:bool=True) -> TreeNode:
      if right: return node if node.right is None else farSubtree(node.right, True)
      return node if node.left is None else farSubtree(node.left, False)
    if found.right:
      xroot = farSubtree(found.right, False)
      xroot.left = found.left
    else:
      xroot = farSubtree(found.left)
      xroot.right = found.right
    return xroot

if __name__ == "__main__":
  solve = Solution()
  solve.deleteNode(buildBinaryTree([5,3,6,2,4,None,7]), key=3)
  solve.deleteNode(buildBinaryTree([5,3,7,2,4,6,8]), key=5)
  solve.deleteNode(buildBinaryTree([5,3,6,2,4,None,7]), key=7)
  solve.deleteNode(buildBinaryTree([]), key=0)



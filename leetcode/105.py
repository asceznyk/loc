# O(m ** n)
class Solution:
  def buildTree(self, preorder:List[int], inorder:List[int]) -> Union[TreeNode,None]:
    def build(preorder:List[int], inorder:List[int]) -> Union[None,TreeNode]:
      if not (preorder or inorder): return
      rval = preorder[0]
      if len(preorder) == len(inorder) == 1: return TreeNode(val=rval)
      preStart, inIdx = 0, inorder.index(rval)
      leftInorder = inorder[:inIdx]
      rightPreStart = preStart+1+len(leftInorder)
      root = TreeNode(val=rval)
      root.left = build(
        preorder[preStart+1:rightPreStart],
        leftInorder
      )
      root.right = build(
        preorder[rightPreStart:len(preorder)],
        inorder[inIdx+1:len(inorder)]
      )
      return root
    return build(preorder, inorder)

# O(n)
class Solution:
  def buildTree(self, preorder:List[int], inorder:List[int]) -> Union[TreeNode,None]:
    def build(
      preStart:int, preEnd:int,
      inStart:int, inEnd:int
    ) -> Union[None,TreeNode]:
      if preStart > preEnd or preStart > len(preorder)-1: return None
      rval = preorder[preStart]
      if preStart == preEnd: return TreeNode(val=rval)
      inIdx = inMap[preorder[preStart]]
      root = TreeNode(val=rval)
      leftSize = inIdx-inStart
      root.left = build(
        preStart+1, preStart+leftSize, inStart, inIdx-1
      )
      root.right = build(
        preStart+1+leftSize, preStart+(inEnd-inStart), inIdx+1, inEnd
      )
      return root
    inMap = {k:v for v,k in enumerate(inorder)}
    root = build(0, len(preorder)-1, 0, len(inorder)-1)
    return root


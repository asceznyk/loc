class Solution:
  def recoverTree(self, root:TreeNode) -> List[int]:
    def buildMap(node:TreeNode, path:str):
      if not node: return
      bMap[node.val] = path
      vals.append(node.val)
      buildMap(node.left, path+'l')
      buildMap(node.right, path+'r')
    def isValid(node:TreeNode, record:bool=False) -> bool:
      if not node: return True
      isLeft = isValid(node.left, record)
      if visited and node.val <= visited[-1]:
        if record and visited[-1] not in wrong: wrong.append(visited[-1])
        return False
      visited.append(node.val)
      isRight = isValid(node.right, record)
      return isLeft and isRight
    def find(node:TreeNode, path:str, i:int) -> TreeNode:
      if i == len(path): return node
      return find(node.right, path, i+1) if path[i] == 'r' else find(node.left, path, i+1)
    wrong = []
    bMap = {}
    vals = []
    visited = []
    if isValid(root, record=True): return
    buildMap(root, "")
    for idA in wrong:
      for idB in vals:
        if idA == idB: continue
        nodeA = find(root, bMap[idA], 0)
        nodeB = find(root, bMap[idB], 0)
        nodeA.val, nodeB.val = idB, idA
        visited = []
        if isValid(root): return
        nodeA.val, nodeB.val = idA, idB 


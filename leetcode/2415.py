from utils import *

def buildBinaryTree(nums:List[Union[int,None]]) -> Union[TreeNode,None]:
  n = len(nums)
  if n <= 0: return None
  i = 0
  root = TreeNode(nums[0])
  queue = deque([root])
  while queue:
    node = queue.popleft()
    if node is None: continue
    l, r = 2*i+1, 2*i+2
    if l <= n-1 and nums[l] is not None:
      node.left = TreeNode(nums[l])
      queue.append(node.left)
    if r <= n-1 and nums[r] is not None:
      node.right = TreeNode(nums[r])
      queue.append(node.right)
    i += 1
  return root

class Solution:
  def reverseOddLevels(self, root:Optional[TreeNode]) -> Optional[TreeNode]:
    def rdfs(node:TreeNode, d:int):
      if not node: return
      if len(visited) == d: visited.append([])
      visited[d].append(node.val)
      rdfs(node.left, d+1)
      rdfs(node.right, d+1)
    visited = []
    rdfs(root, 0)
    treeList = []
    for i, level in enumerate(visited):
      if i%2:
        for j in range(len(level)-1, -1, -1):
          treeList.append(level[j])
        continue
      for j in range(len(level)): treeList.append(level[j])
    return buildBinaryTree(treeList)



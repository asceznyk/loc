class Solution:
  def sortedArrayToBST(self, nums:List[int]) -> Optional[TreeNode]:
    def dfs(arr:List[int]) -> TreeNode:
      n = len(arr)
      if n == 0:
        return None
      if n == 1:
        return TreeNode(arr[0])
      pivot = n//2
      node = TreeNode(arr[pivot])
      node.left = dfs(arr[:pivot])
      node.right = dfs(arr[pivot+1:])
      return node
    return dfs(nums)



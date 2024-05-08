class Codec:

  def serialize(self, root:TreeNode) -> str:
    m, k = 0, 0
    data = {}
    queue = deque([root])
    while queue:
      node = queue.popleft()
      if node is None:
        k += 1
        continue
      data[k] = node.val
      m = k
      k += 1
      queue.append(node.left)
      queue.append(node.right)
    if not data: return ''
    enc = []
    for e in range(m+1):
      if data.get(e) is None:
        enc.append('#')
        continue
      enc.append(str(data[e]))
    return ','.join(enc)

  def deserialize(self, data:str) -> TreeNode:
    if not data: return None
    nums = [None if x == '#' else int(x) for x in data.split(',')]
    n = len(nums)
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


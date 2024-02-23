class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []

class Solution:
  def cloneGraph(self, node:Node) -> Node:
    def rdfs(curr:Node):
      if curr.val in store: return store[curr.val]
      copy = Node(curr.val)
      store[curr.val] = copy
      for adj in curr.neighbors: copy.neighbors.append(rdfs(adj))
      return copy
    store = {}
    return rdfs(node) if node else None


class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []

class Solution:
  def cloneGraph(self, node:Node) -> Node:
    def rdfs(curr:Node):
      new = store[curr.val]
      for adj in curr.neighbors:
        if adj.val in store:
          new.neighbors.append(store[adj.val])
          continue
        store[adj.val] = Node(adj.val)
        new.neighbors.append(store[adj.val])
        rdfs(adj)
      return
    if not node: return None
    store = {node.val:Node(node.val)}
    rdfs(node)
    return store[node.val]



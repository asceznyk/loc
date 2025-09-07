class Solution:
  def minimumDiameterAfterMerge(
    self, edges1:List[List[int]], edges2:List[List[int]]
  ) -> int:
    def dfs(u:int, tree:List[List[int]], visited:List[int]) -> Tuple[int,int]:
      visited[u] = 1
      d, w = 0, u
      for v in tree[u]:
        if visited[v]: continue
        (x, s) = dfs(v, tree, visited)
        if x+1 > d:
          d = x+1
          w = s
      return d, w
    def diameter(u:int, tree:List[List[int]]) -> int:
      _, w = dfs(u, tree, [0 for _ in range(len(tree))])
      d, _ = dfs(w, tree, [0 for _ in range(len(tree))])
      return d
    d1, d2 = 0, 0
    n, m = len(edges1) + 1, len(edges2) + 1
    tree1 = [[] for _ in range(n)]
    tree2 = [[] for _ in range(m)]
    for edge in edges1:
      [u, v] = edge
      tree1[u].append(v)
      tree1[v].append(u)
    for edge in edges2:
      [u, v] = edge
      tree2[u].append(v)
      tree2[v].append(u)
    d1 = diameter(0, tree1)
    d2 = diameter(0, tree2)
    return max(d1, d2, (d1+1)//2 + (d2+1)//2 + 1)


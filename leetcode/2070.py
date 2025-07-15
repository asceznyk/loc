class Solution:
  def maximumBeauty(self, items:List[List[int]], queries:List[int]) -> List[int]:
    items = sorted(items, key=lambda x: x[0])
    beauty = []
    x = 0
    for (p, b) in items:
      x = max(b, x)
      beauty.append((p, x))
    res = []
    prices = [p for p, _ in beauty]
    for q in queries:
      idx = bisect.bisect_right(prices, q, lo=0, hi=len(prices)) - 1
      if idx == -1:
        res.append(0)
        continue
      res.append(beauty[idx][1])
    return res


class Solution:
  def minNumberOperations(self, target:List[int]) -> int:
    downhills = [[]]
    downhills[0].append(target[0])
    for x in target[1:]:
      if x > downhills[-1][-1]:
        downhills.append([])
      downhills[-1].append(x)
    moves = 0
    for i, dh in enumerate(downhills):
      moves += max(dh)
      if i == len(downhills)-1: continue
      moves -= min(dh)
    return moves



class Solution:
  def findLeastNumOfUniqueInts(self, arr:List[int], k:int) -> int:
    counts, s = Counter(arr), 0 
    for i, v in enumerate(sorted(counts.values())):
      s += v
      if s > k: return len(counts)-i
    return 0 


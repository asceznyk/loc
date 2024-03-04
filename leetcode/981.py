class TimeMap:

  def __init__(self):
    self.tmap = {}

  def set(self, key:str, value:str, timestamp:int):
    if not self.tmap.get(key): self.tmap[key] = []
    self.tmap[key].append((value, timestamp))

  def get(self, key:str, timestamp:int) -> str:
    res = ""
    vals = self.tmap.get(key, [])
    l, r = 0, len(vals)-1
    while l <= r:
      m = (l+r)//2
      if vals[m][1] <= timestamp:
        res = vals[m][0]
        l = m+1
      else: r = m-1
    return res



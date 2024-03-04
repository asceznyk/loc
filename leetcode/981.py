class TimeMap:

  def __init__(self):
    self.tmap = {}

  def set(self, key:str, value:str, timestamp:int):
    if not self.tmap.get(key): self.tmap[key] = []
    self.tmap[key].append((value, timestamp))

  def get(self, key:str, timestamp:int) -> str:
    res = ""
    vals = self.tmap.get(key, [])
    a, b = 0, len(vals)-1
    while a <= b:
      k = (a+b)//2
      if vals[k][1] <= timestamp:
        res = vals[k][0]
        a = k+1
      else: b = k-1
    return res



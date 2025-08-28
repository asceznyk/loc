class LRUCache:
  def __init__(self, capacity:int):
    self.capacity = capacity
    self.uMap = {}
  def get(self, key:int) -> int:
    if self.uMap.get(key) is None: return -1
    value = self.uMap.get(key)
    del self.uMap[key]
    self.uMap[key] = value
    return self.uMap[key]
  def put(self, key:int, value:int) -> None:
    if self.uMap.get(key) is None and len(self.uMap) == self.capacity:
      old = list(self.uMap.keys())[0]
      del self.uMap[old]
    if self.uMap.get(key):
      del self.uMap[key]
    self.uMap[key] = value



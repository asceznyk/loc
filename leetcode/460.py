from sortedcontainers import SortedDict
from collections import OrderedDict

class LFUCache:
  def __init__(self, capacity:int):
    self.capacity = capacity
    self.data = {}
    self.cntIdx = {}
    self.distFreq = SortedDict()
  def metaUpdate(self, key:int):
    cnt = self.cntIdx[key]
    newCnt = cnt+1
    self.cntIdx[key] = newCnt
    del self.distFreq[cnt][key]
    if not len(self.distFreq.get(cnt)):
      del self.distFreq[cnt]
    if self.distFreq.get(newCnt) is None:
      self.distFreq[newCnt] = OrderedDict()
    self.distFreq[newCnt][key] = True
  def get(self, key:int) -> int:
    if self.data.get(key) is None:
      return -1
    self.metaUpdate(key)
    return self.data[key]
  def put(self, key:int, value:int):
    if self.data.get(key) is None:
      if len(self.data) == self.capacity:
        lfuCnt = next(iter(self.distFreq))
        lruKey = next(iter(self.distFreq[lfuCnt]))
        del self.distFreq[lfuCnt][lruKey]
        if not len(self.distFreq[lfuCnt]):
          del self.distFreq[lfuCnt]
        del self.cntIdx[lruKey]
        del self.data[lruKey]
      self.cntIdx[key] = 1
      if self.distFreq.get(1) is None:
        self.distFreq[1] = OrderedDict()
      oset = self.distFreq[1]
      oset[key] = True
      self.data[key] = value
      return
    self.metaUpdate(key)
    self.data[key] = value









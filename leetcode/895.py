class FreqStack:
    def __init__(self):
      self.freq = {}
      self.data = []
    def push(self, val:int):
      if not self.freq.get(val,0): self.freq[val] = 0
      self.freq[val] += 1
      index = self.freq[val]-1
      if index == len(self.data):
        self.data.append([])
        self.data[-1].append(val)
        return
      self.data[index].append(val)
      return
    def pop(self) -> int:
      val = self.data[-1].pop()
      if len(self.data[-1]) == 0:
        self.data.pop()
      self.freq[val] -= 1
      return val


class StockSpanner:

  def __init__(self):
    self.day = 0
    self.stack = [(self.day, (10**5)+1)]
    
  def next(self, price:int) -> int:
    self.day += 1
    while price >= self.stack[-1][1]: self.stack.pop()
    span = self.day - self.stack[-1][0]
    self.stack.append((self.day, price))
    return span


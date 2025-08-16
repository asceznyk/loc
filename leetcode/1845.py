class SeatManager:
    
  def __init__(self, n: int):
    self.heap = heapify([i+1 for i in range(n)])

  def reserve(self) -> int: return heappop(self.heap)

  def unreserve(self, seatNumber: int):
    heappush(self.heap, seatNumber)



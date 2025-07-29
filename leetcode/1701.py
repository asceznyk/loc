class Solution:
  def averageWaitingTime(self, customers:List[List[int]]) -> float:
    n = len(customers)
    ans, prev = 0.0, customers[0][0] 
    for customer in customers:
      [arrival, dur] = customer
      end = dur + (prev if prev > arrival else arrival)
      ans += (end - arrival)
      prev = end
    return 0.0

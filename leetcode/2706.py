class Solution:
  def buyChoco(self, prices:List[int], money:int) -> int:
    prices.sort()
    cost = prices[0]+prices[1]
    return money if cost > money else money-cost 


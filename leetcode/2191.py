class Solution:
  def sortJumbled(self, mapping:List[int], nums:List[int]) -> List[int]:
    mapping = {str(i):v for i,v in enumerate(mapping)}
    pairs = []
    for num in nums:
      curr = str(num)
      val = ""
      for digit in curr:
        val += str(mapping[digit])
      pairs.append((int(val),curr))
    return [int(t[1]) for t in sorted(pairs, key=lambda x: x[0])]


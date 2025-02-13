class Solution:
  def majorityElement(self, nums:List[int]) -> List[int]:
    freq = {}
    n = len(nums)
    for x in nums:
      freq[x] = freq.get(x, 0)+1
    ans = []
    for k, v in freq.items():
      if v > (n//3): ans.append(k)
    return ans





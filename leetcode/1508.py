class Solution:
  def rangeSum(self, nums:List[int], n:int, left:int, right:int) -> int:
    prefix = [0 for _ in range(n)]
    p = 0
    for i in range(n):
      p += nums[i]
      prefix[i] = p
    sumSubarray = [0 for _ in range(n**2)]
    for i in range(n):
      for j in range(i, n):
        if j == i: sumSubarray[(i*n)+j] = prefix[j]
        else: sumSubarray[(i*n)+j] = prefix[j] - prefix[i]
    newArr = [] 
    for x in sumSubarray:
      if x != 0: newArr.append(x)
    newArr = sorted(newArr)
    ans = 0
    for i in range(left-1, right):
      ans += newArr[i]
    return ans % ((10**9)+7)


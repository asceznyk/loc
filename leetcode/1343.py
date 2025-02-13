class Solution:
  def numOfSubarrays(self, arr:List[int], k:int, threshold:int) -> int:
    n = len(arr)
    currSum, cnt = sum(arr[:k]), 0
    for i in range(k-1, n):
      if (currSum/k) >= threshold: cnt += 1
      currSum -= arr[i-(k-1)]
      if i == n-1: continue
      currSum += arr[i+1]
    return cnt



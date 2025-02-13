
class Solution:
  def isPowerOfTwo(self, n:int) -> bool:
    if n <= 0: 
      return False
    rep = bin(n)[2:]
    cnt = 0
    for i in rep:
      cnt += int(i)
      if cnt > 1:
        return False
    return (cnt == 1)

if __name__ == "__main__":
  sol = Solution()
  sol.isPowerOfTwo(0)
  sol.isPowerOfTwo(1)
  sol.isPowerOfTwo(3)
  sol.isPowerOfTwo(16)



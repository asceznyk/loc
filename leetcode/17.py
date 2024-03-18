from utils import *

class Solution:
  def letterCombinations(self, digits: str) -> List[str]:
    def dfs(s:str, d:int=0):
      if not strGrp: return
      if d == len(digits):
        visited.append(s)
        return
      for c in strGrp[d]: dfs(f"{s}{c}", d+1)
    digitMap = {
      2:"abc",
      3:"def",
      4:"ghi",
      5:"jkl",
      6:"mno",
      7:"pqrs",
      8:"tuv",
      9:"wxyz"
    }
    strGrp = [digitMap[int(d)] for d in digits]
    visited = []
    dfs("")
    return visited


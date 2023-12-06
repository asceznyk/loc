from typing import List

class Solution:
  def encode(self, strs:List[str]):
    return "*".join(strs)
  def decode(self, s:str):
    return s.split("*")



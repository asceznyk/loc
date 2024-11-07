class Solution:
  def isNumber(self, s:str) -> bool:
    variants = ["inf", "INF", "Inf", "Nan", "nan"]
    for v in variants:
      if v in s:
        return False
    try: 
      s = float(s)
      return True
    except:
      return False
    

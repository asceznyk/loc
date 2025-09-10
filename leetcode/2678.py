class Solution:
  def countSeniors(self, details:List[str]) -> int:
    ans = 0
    for detail in details:
      if int(details[11] + detail[12]) <= 60: continue
      ans += 1
    return ans



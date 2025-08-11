class Solution:
  def dividePlayers(self, skill:List[int]) -> int:
    skill = sorted(skill)
    n = len(skill)
    if n == 2:
      return (skill[0] * skill[1])
    l, r = 0, n-1
    curr = usum = skill[l] + skill[r]
    chem = 0
    while l < r and curr == usum:
      curr = skill[l] + skill[r]
      chem += (skill[l]*skill[r])
      l += 1
      r -= 1
    return chem if l > r and curr == usum else -1


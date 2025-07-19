class Solution:
  def countOfAtoms(self, formula:str) -> str:
    i = 0
    n = len(formula)
    stack = [{}]
    counts = {}
    while i < n:
      x = formula[i]
      if x == '(':
        stack.append({})
        i += 1
      elif x == ')':
        if i+1 == n:
          break
        elemCount = stack.pop()
        factor = ''
        i += 1
        while i < n and (not formula[i].isalpha()) and not (formula[i] in '()'):
          factor += formula[i]
          i += 1
        factor = (1 if factor == '' else int(factor))
        topCount = stack[-1]
        for e, v in elemCount.items():
          if not topCount.get(e,0): topCount[e] = 0
          topCount[e] += v*factor
      elif x.isalpha():
        topCount = stack[-1]
        if i+1 == n or not formula[i+1].islower():
          key = x
          if not topCount.get(key,0): topCount[key] = 0
          i += 1
        else:
          key = x
          while formula[i+1].islower():
            key += formula[i+1]
            i += 1
          i += 1
          if not topCount.get(key,0): topCount[key] = 0
        num = ''
        while i < n and (not formula[i].isalpha()) and not (formula[i] in '()'):
          num += formula[i]
          i += 1
        topCount[key] += (1 if num == '' else int(num))
    while stack:
      topCount = stack.pop()
      for e, v in topCount.items():
        if not counts.get(e,0): counts[e] = 0
        counts[e] += v
    res = sorted([(e,v) for e,v in counts.items()], key=lambda x:x[0])
    ans = ""
    for e, v in res:
      ans += f"{e}{v if v > 1 else ''}"
    return ans



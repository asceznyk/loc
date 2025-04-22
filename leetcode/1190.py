class Solution:
  def reverseParentheses(self, s:str) -> str:
    stack = []
    rev = []
    m = ''
    for i,c in enumerate(s):
      if c == '(':
        stack.append(i)
        continue
      elif c == ')':
        l = stack.pop()
        s = s[:l]+'_'+s[l+1:i][::-1]+'_'+s[i+1:]
    return s.replace('_','')



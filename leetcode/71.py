class Solution:
  def simplifyPath(self, path:str) -> str:
    fsdirs = path.split("/")
    stack = []
    for d in fsdirs:
      if d == "..":
        if len(stack): stack.pop()
        continue
      if d == "." or d == "": continue
      stack.append(d)
    ans = "/"
    for i, s in enumerate(stack):
      ans += f"{s}/" if i < len(stack)-1 else s
    return ans


class Solution:
  def fullJustify(self, words:List[str], maxWidth:int) -> List[str]:
    def justify(grp:List[str]) -> str:
      if len(grp) == 1:
        word = grp[0]
        return word + ' '*(maxWidth-len(word))
      parts, slen = [], 0 
      lastWord = grp[-1]
      for word in grp[:-1]:
        parts.append(word + ' ')
        slen += 1+len(word)
      slen += len(lastWord)
      keep = (slen < maxWidth) 
      while len(parts) and keep:
        for i in range(len(parts)):
          parts[i] += ' '
          slen += 1
          if slen == maxWidth:
            keep = False
            break
      return ''.join(parts+[lastWord])
    lines = []
    line = ''
    for word in words:
      line += word + ' '
      if len(line)-1 > maxWidth:
        grp = line.split()
        line = grp.pop() + ' '
        lines.append(justify(grp)) 
    llen = len(line.rstrip())
    if llen > 0:
      lines.append(line.rstrip() + (' '*(maxWidth-llen)))
    return lines
     


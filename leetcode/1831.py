class Solution:
  def areSentencesSimilar(self, sentence1:str, sentence2:str) -> bool:
    n = len(sentence1)
    m = len(sentence2)
    sentA, sentB = sentence1, sentence2
    if m >= n:
      sentA, sentB = sentence2, sentence1
    wordsA, wordsB = sentA.split(' '), sentB.split(' ')
    if not (set(wordsB) <= set(wordsA)):
      return False
    i, j = 0, 0
    a, b = len(wordsA), len(wordsB)
    for i in range(b+1):
      start = wordsB[:i]
      end = wordsB[i:]
      wrapStart, wrapEnd = '', ''
      for x in range(len(start)): wrapStart += f"{wordsA[x]} "
      for x in range(a-len(end), a): wrapEnd += f"{wordsA[x]} "
      bStart = ' '.join(start)
      bEnd = ' '.join(end)
      if wrapStart.rstrip() == bStart and wrapEnd.rstrip() == bEnd:
        return True
    return False


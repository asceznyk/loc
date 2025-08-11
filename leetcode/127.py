class Solution:
  def ladderLength(self, beginWord:str, endWord:str, wordList:List[str]) -> int:
    if endWord not in wordList or beginWord == endWord: 
      return 0
    queue = deque([(beginWord, 1)])
    visited = {}
    endDist = 10**9
    patternMap = {}
    for word in wordList:
      for i in range(len(word)):
        card = word[:i] + '*' + word[(i+1):]
        [left, right] = card.split('*')
        if word.startswith(left) and word.endswith(right):
          if not patternMap.get(card,0): patternMap[card] = []
          patternMap[card].append(word)
    while queue:
      word, dist = queue.popleft()
      if visited.get(word,0) or word == endWord:
        endDist = min(endDist, dist) if word == endWord else endDist
        continue
      visited[word] = True
      for i in range(len(word)):
        card =  word[:i] + '*' + word[(i+1):]
        for cWord in patternMap.get(card, []):
          queue.append((cWord, dist+1))
    return endDist if endDist != 10**9 else 0



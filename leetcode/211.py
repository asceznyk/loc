class WordDictionary:

  def __init__(self):
    self.trie = {}

  def addWord(self, word:str):
    tree = self.trie
    for char in word:
      if not tree.get(char): tree[char] = {}
      tree = tree[char]
    tree['*'] = 1

  def search(self, word:str) -> bool:
    def dfs(tree:Dict, c:int) -> bool:
      if c >= len(word): return bool(tree.get('*'))
      if word[c] != ".":
        return False if not bool(tree.get(word[c])) else dfs(tree[word[c]], c+1)
      for k in tree:
        if k == "*": continue
        if dfs(tree[k], c+1): return True
      return False
    tree = self.trie
    return dfs(tree, 0)


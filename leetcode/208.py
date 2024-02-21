class Trie:

  def __init__(self):
    self.trie = {}

  def insert(self, word:str):
    tree = self.trie
    for char in word:
      if char not in tree: tree[char] = {}
      tree = tree[char]
    tree['*'] = True

  def search(self, word:str, full:bool=True) -> bool:
    tree = self.trie
    for char in word:
      if (char not in tree): return False
      tree = tree[char]
    return '*' in tree if full else True

  def startsWith(self, prefix:str) -> bool:
    return self.search(prefix, False)


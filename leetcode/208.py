class Trie:

  def __init__(self):
    self.trie = {}

  def insert(self, word:str):
    tree = self.trie
    for char in word:
      if not tree.get(char): tree[char] = {}
      tree = tree[char]
    tree['*'] = True

  def search(self, word:str, full:bool=True) -> bool:
    tree = self.trie
    for char in word:
      if not tree.get(char): return False
      tree = tree[char]
    return (tree.get('*') is not None) if full else True

  def startsWith(self, prefix:str) -> bool:
    return self.search(prefix, False)


from typing import List

class Trie:

  def __init__(self):
    self.trie = {}

  def insert(self, word:str):
    tree = self.trie
    for char in word:
      if not tree.get(char): tree[char] = {}
      tree = tree[char]
    tree['*'] = True

  def prefix(self):
    tree = self.trie
    s = ""
    keys = list(tree.keys())
    while len(keys) == 1:
      key = keys[0]
      s += key.replace('*','')
      tree = tree[key]
      if tree == True:
        break
      keys = list(tree.keys())
    return s

class Solution:
  def longestCommonPrefix(self, strs:List[str]) -> str:
    trie = Trie()
    for word in strs:
      trie.insert(word)
    return trie.prefix()


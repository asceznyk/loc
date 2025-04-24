class TrieNode {
public:
  TrieNode* child[26];
  int visits = 0;
  bool isWord;
  TrieNode() {
    isWord = false;
    for (auto &a : child) a = nullptr;
  }
};

class Trie {
public:
  TrieNode* root;
  Trie() {
    root = new TrieNode();
  }
  void insert(string s) {
    TrieNode *p = root;
    for (auto &a : s) {
      int i = a-'a';
      if (!p->child[i]) p->child[i] = new TrieNode();
      p = p->child[i];
      p->visits++;
    }
    p->isWord = true;
  }
  int count(string s) {
    TrieNode* p = root;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      p = p->child[s[i]-'a'];
      cnt += p->visits;
    }
    return cnt;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string>& words) {
    int n = words.size();
    vector<int> res(n);
    Trie* trie = new Trie();
    for (string& word: words) trie->insert(word);
    for (int i = 0; i < n; i++) res[i] = trie->count(words[i]);
    return res;
  }
};


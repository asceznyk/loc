class TrieNode {
public:
  TrieNode* child[26];
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
    }
    p->isWord = true;
  }
};

class Solution {
public:
  void dfs(
    vector<vector<char>>& board, string cand, TrieNode* node,
    int i, int j, vector<string>& res
  ) {
    if (board[i][j] == '#')
      return;
    char tmp = board[i][j];
    node = node->child[tmp-'a'];
    if (node == nullptr) return;
    if (node->isWord) {
      res.push_back(cand+tmp);
      node->isWord = false;
    }
    board[i][j] = '#';
    if (i > 0) dfs(board, cand+tmp, node, i-1, j, res);
    if (i < board.size()-1) dfs(board, cand+tmp, node, i+1, j, res);
    if (j > 0) dfs(board, cand+tmp, node, i, j-1, res);
    if (j < board[0].size()-1) dfs(board, cand+tmp, node, i, j+1, res);
    board[i][j] = tmp;
  }
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* trie = new Trie();
    int m = board.size(), n = board[0].size();
    for (auto& word: words) trie->insert(word);
    vector<string> res;
    TrieNode* node = trie->root;
    for (int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) { 
        dfs(board, "", node, i, j, res);
      }
    }
    return res;
  }
};



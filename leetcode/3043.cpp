class TrieNode {
public:
  TrieNode* child[10];
  TrieNode() {
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
    TrieNode* p = root;
    for (auto &a: s) {
      int i = a-'0';
      if (!p->child[i]) p->child[i] = new TrieNode();
      p = p->child[i];
    }
  }
  int commonPref(string s) {
    TrieNode* p = root;
    int cnt = 0;
    for (auto &a: s) {
      int i = a-'0';
      if (!p->child[i]) break;
      p = p->child[i];
      cnt++;
    }
    return cnt;
  }
};

class Solution {
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    int ans = 0;
    int n = arr1.size(), m = arr2.size();
    Trie* trie = new Trie();
    for (int i = 0; i < n; i++) {
      string snum = to_string(arr1[i]);
      trie->insert(snum);
    }
    for (int j = 0; j < m; j++) {
      string curr = to_string(arr2[j]);
      ans = max(ans, trie->commonPref(curr));
    }
    return ans;    
  }
};


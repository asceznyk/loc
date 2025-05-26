#include "../utils.h"

class Solution {
public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size(), m = queries.size();
    vector<bool> vowels(26);
    vowels[0] = true;
    vowels[4] = true;
    vowels[8] = true;
    vowels[14] = true;
    vowels[20] = true;
    vector<int> res(m);
    vector<int> prefix(n);
    int p = 0;
    for (int i = 0; i < n; i++) {
      string word = words[i];
      p += (int)(vowels[word[0]-'a'] && vowels[word[word.length()-1]-'a']);
      prefix[i] = p;
    }
    for (int k = 0; k < m; k++) {
      int l = queries[k][0], r = queries[k][1];
      if (l == 0) {
        res[k] = prefix[r];
        continue;
      }
      res[k] = prefix[r] - prefix[l-1]; 
    }
    return res;
  }
};

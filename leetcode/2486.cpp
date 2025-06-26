class Solution {
public:
  int appendCharacters(string s, string t) {
    int m = s.length(), n = t.length();
    int p = 0; int q = 0;
    while (p < m) {
      if (s[p] == t[q]) {
        p++;
        q++;
        continue;
      }
      p++;
    }
    return n-q;
  }
};




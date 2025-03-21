class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    int l = 0, r = n-1, p = l, q = r;
    int pre = l, suf = r; 
    while (p < q && s[p] == s[q]) {
      p = l, pre = l;
      while (l < n && s[l] == s[p]) {
        p = l;
        l++;
      }
      q = r, suf = r;
      while (r > -1 && s[r] == s[q]) {
        q = r;
        r--;
      }
    }
    if (p > q) return 0;
    return suf-pre+1;
  }
};


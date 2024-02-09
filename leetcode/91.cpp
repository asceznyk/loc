class Solution {
public:
  int numDecodings(string s) {
    if((int)s[0]-'0' == 0) return 0;
    int n = s.length();
    int r = 1, p = 1, q = 1;
    if((int)s[n-1]-'0' == 0) p = 0;
    for(int i = n-2; i >= 0; i--) {
      int x = s[i]-'0';
      if(x == 0) r = 0;
      else r = p;
      if(x == 1 || (x == 2 && (int)s[i+1]-'0' <= 6)) r += q;
      q = p;
      p = r;
    }
    return r;
  }
};

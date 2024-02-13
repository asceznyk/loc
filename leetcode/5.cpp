class Solution {
private:
  void expandFromMiddle(string s, int l, int r, int& lIdx, int& maxLen) { 
    while(l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
    }
    int len = r-l-1; 
    if(len > maxLen) {
      lIdx = l+1;
      maxLen = len;
    }
  }
public:
  string longestPalindrome(string s) {
    int maxLen = 1;
    int lIdx = 0;
    int n = s.length();
    for(int i = 0; i < n; i++) {
      expandFromMiddle(s, i-1, i+1, lIdx, maxLen);
      expandFromMiddle(s, i, i+1, lIdx, maxLen);
    }
    return s.substr(lIdx, maxLen);
  }
};



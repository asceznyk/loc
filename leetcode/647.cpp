class Solution {
private:
  void expandFromMiddle(string s, int l, int r, int& count) { 
    while(l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
      count++;
    }
  }
public:
  int countSubstrings(string s) {
    int n = s.length();
    int count = 0;
    for(int i = 0; i < n; i++) {
      expandFromMiddle(s, i-1, i+1, count);
      expandFromMiddle(s, i, i+1, count);
      count++;
    }
    return count;
  }
};



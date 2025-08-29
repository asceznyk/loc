typedef long long ll;

class Solution {
public:
  ll minimumSteps(string s) {
    int n = s.length();
    ll cnt = 0;
    int r = n-1;
    for (int i = r; i > -1; i--) {
      if (s[i] == '0') continue;
      cnt += (r-i)*1LL;
      r--;
    }
    return cnt;
  }
};


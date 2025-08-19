typedef long long ll;

class Solution {
public:
  int countNodes(ll i, ll j, ll n) {
    ll nodes = 0;
    while (i <= n) {
      nodes += min(n+1, j) - i;
      i *= 10LL;
      j *= 10LL;
    }
    return static_cast<int>(nodes);
  }
  int findKthNumber(int n, int k) {
    int i = 1;
    k--;
    while (k > 0) {
      int s = countNodes(1LL*i, 1LL*(i+1), 1LL*n);
      if (k >= s) {
        k -= s;
        i++;
      } else {
        i *= 10;
        k--;
      }
    }
    return i;
  }
};


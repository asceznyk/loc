typedef long long ll;

class Solution {
public:
  const int MOD = 1e9+7;
  int numberOfWays(string corridor) {
    int n = corridor.length();
    int sCnt = 0;
    for (int i = 0; i < n; i++) {
      if(corridor[i] == 'P') continue;
      sCnt++;
    }
    if (sCnt % 2 || sCnt == 0) return 0;
    if (sCnt == 2) return 1;
    sCnt = 0;
    int i = 0;
    ll ans = 1;
    while (i < n) {
      if (corridor[i] == 'S') sCnt++;
      if (sCnt < 2) {
        i++;
        continue;
      }
      int l = i;
      i++;
      while (i < n && corridor[i] != 'S') i++;
      if (i >= n) break;
      ans *= (i-l)*1LL;
      ans %= MOD;
      sCnt = 1;
      i++;
    }
    return static_cast<int>(ans % MOD);
  }
};



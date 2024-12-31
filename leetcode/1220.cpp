const int MOD = 1e9 + 7;

typedef long long ll;

class Solution {
public:
  int countVowelPermutation(int n) {
    vector<ll> curr(5);
    vector<ll> prev(5);
    for (int j = 0; j < 5; j++) prev[j] = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
      curr[0] = (prev[1] + prev[2] + prev[4]) % MOD;
      curr[1] = (prev[0] + prev[2]) % MOD;
      curr[2] = (prev[1] + prev[3]) % MOD;
      curr[3] = (prev[2]) % MOD;
      curr[4] = (prev[2] + prev[3]) % MOD;
      prev = curr;
    }
    for (int j = 0; j < 5; j++) ans += prev[j];
    return (int)(ans % MOD);
  }
};


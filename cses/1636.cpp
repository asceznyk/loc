#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for(int k = 0; k < n; k++) cin >> coins[k];
  vector<ll> counts(x+1, 0);
  counts[0] = 1;
  for(int k = 1; k <= n; k++) {
    for(int i = 0; i <= x; i++) {
      if(i-coins[k-1] < 0) continue; 
      counts[i] += counts[i-coins[k-1]];
      counts[i] %= MOD;
    }
  }
  cout << counts[x] << '\n';
  return 0;
}

#include <iostream>
#include <bits/stdc++.h>

//#include "../utils.h"

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

// time - O(n*k), space - O(n*k) 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for(int k = 0; k < n; k++) cin >> coins[k];
  vector<vector<ll>> counts(x+1, vector<ll>(n+1));
  counts[0][0] = 1;
  for(int k = 1; k <= n; k++) {
    for(int i = 0; i <= x; i++) {
      if(i-coins[k-1] >= 0) counts[i][k] += counts[i-coins[k-1]][k];
      counts[i][k] += counts[i][k-1];
      counts[i][k] %= MOD;
    }
  }
  cout << counts[x][n] << '\n';
  return 0;
}

//time - O(n*k), space - O(n)
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

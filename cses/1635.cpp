#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n, 0);
  vector<int> count(x+1, 0);
  for(int j = 0; j < n; j++) cin >> coins[j];
  count[0] = 1;
  for(int i = 1; i <= x; i++) {
    for(int j = 0; j < n && i-coins[j] >= 0; j++) {
      count[i] += count[i-coins[j]];
      count[i] %= MOD;
    }
  }
  cout << count[x] << endl;
  return 0;
}


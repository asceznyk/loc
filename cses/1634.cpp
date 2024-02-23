#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n, 0);
  for(int i = 0; i < n; i++) cin >> coins[i];
  vector<int> minc(x+1, INT_MAX-5);
  minc[0] = 0;
  for(int i = 1; i <= x; i++) {
    for(auto y: coins) {
      if(i-y < 0) continue;
      minc[i] = min(minc[i-y]+1, minc[i]);
    }
  }
  cout << (minc[x] == INT_MAX-5 ? -1 : minc[x]) << endl;
  return 0;
}


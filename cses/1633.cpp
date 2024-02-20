#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int mod = 1e+9+7;
  int n;
  cin >> n;
  vector<int> count(n+1, 0);
  count[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int x = 1; x <= 6 && i-x >= 0; x++) {
      count[i] += count[i-x];
      count[i] %= mod;
    }
  }
  cout << count[n] << endl;
  return 0;
}


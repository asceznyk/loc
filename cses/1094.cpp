#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n; 
  cin >> n;
  vector<ll> nums(n);
  for(int i = 0; i < n; i++) cin >> nums[i];
  ll p = 0, moves = 0;
  for(int i = 0; i < n; i++) {
    ll c = nums[i];
    if(c < p) {
      c += p-nums[i];
      moves += p-nums[i];
    };
    p = c;
  }
  cout << moves << endl;
  return 0;
}


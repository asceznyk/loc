#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int solve(vector<ll>& a, vector<ll>& b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int n = a.size();
  int k = 0;
  int r = n-1;
  ll p = 1;

  ll amax = *max_element(a.begin(), a.end());
  ll bmax = *max_element(b.begin(), b.end());
  if(amax <= bmax) {
    cout << 0 << endl;
    return 0;
  }

  for(int i = n; i > 0; --i) {
    while(r >= 0 && a[r] > b[i-1]) {
      r--;
      k++;
    }
    p = p * max(k-(n-i), 0) % MOD;
  }

  cout << p << endl;
  return 1;
}

int main() { 
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);

    for(int i = 0; i < a.size(); ++i) {
      cin >> a[i];
    }

    for(int i = 0; i < b.size(); ++i) {
      cin >> b[i];
    }

    int solved = solve(a, b);
  }
  return 0;
}


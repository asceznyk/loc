#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll m = 0LL, s = 0LL, p = 0LL;
  for (int i = 1; i < n+1; i++) {
    int x;
    cin >> x;
    p += x;
    ll b = 2*i - x;
    s = max(s+b, b);
    m = max(m, s);
  }
  cout << p + m << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}




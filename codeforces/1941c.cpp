#include <iostream>
#include <string>

using namespace std;

void solve() {
  int n; 
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  if (n < 3) {
    cout << ans << '\n';
    return;
  }
  string p = "";
  for (int i = 0; i < n; i++) {
    p += s[i];
    if (p.size() < 3) continue;
    int l = (int)p.size();
    string t = string() + p[l-3] + p[l-2] + p[l-1];
    if (t == "map" || t == "pie") {
      ans++;
      p = "";
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

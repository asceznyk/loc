#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string b;
  cin >> b;
  int c = 0, cmax = 0, p = 0, s = 0;
  for (int i = b.length()-1; (i > -1 && b[i] == '0'); --i) s++;
  for (int i = 0; (i < b.length() && b[i] == '0'); ++i) p++;
  cmax = max(s+p, cmax);
  for (int i = 0; i < b.length(); ++i) {
    if(b[i] == '0') c++;
    else {
      cmax = max(c, cmax);
      c = 0;
    }
  }
  cout << cmax << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}


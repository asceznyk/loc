#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == (n*n)-1) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  bool is_right = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (k) {
        cout << "U";
        k--;
      } else if (i < n-1) cout << "D";
      else if(is_right) cout << "L";
      else {
        cout << "R";
        is_right = true;
      }
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}



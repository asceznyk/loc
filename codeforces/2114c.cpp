#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int p = arr[0], cnt = 1;
  for (int i = 1; i < n; i++) {
    int x = arr[i];
    if (p+1 >= x) continue;
    cnt++;
    p = x;
  }
  cout << cnt << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

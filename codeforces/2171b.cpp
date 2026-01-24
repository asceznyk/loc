#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  if (arr[0] != -1 && arr[n-1] != -1) cout << abs(arr[n-1] - arr[0]) << '\n';
  else cout << 0 << '\n';
  if (arr[0] == -1) arr[0] = arr[n-1];
  if (arr[n-1] == -1) arr[n-1] = arr[0];
  for (int i = 0; i < n; ++i) cout << (arr[i] > -1 ? arr[i] : 0) << " ";
  cout << "\n";
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

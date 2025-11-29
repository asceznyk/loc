#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n-2; i++) {
    int k = arr[i];
    arr[i] -= k;
    arr[i+1] -= 2*k;
    arr[i+2] -= k;
    if (arr[i+1] < 0 || arr[i+2] < 0) {
      cout << "NO" << "\n";
      return;
    }
  }
  (arr[n-2] > 0 || arr[n-1] > 0 || arr[n-2] < 0 || arr[n-1] < 0) 
    ? cout << "NO" << "\n" 
    : cout << "YES" << "\n";
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

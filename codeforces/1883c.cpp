#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = INT_MAX, cnt = 0;
  for (int x: arr) {
    if (!(x%k)) {
      ans = 0;
      break;
    }
    if (!(x%2)) cnt++;
    ans = min(ans, (k - x%k));
  }
  if (k == 4) 
    ans = min(ans, max(0, 2-cnt));
  cout << ans << "\n";
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}



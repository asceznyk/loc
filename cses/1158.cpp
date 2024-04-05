#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {
  int n, x;
  cin >> n;
  cin >> x;
  vector<int> prices(n);
  for(int i = 0; i < n; i++) cin >> prices[i];
  vector<int> pages(n);
  for(int i = 0; i < n; i++) cin >> pages[i];
  vector<int> dp(x+1);
  for(int i = 0; i < n; i++) {
    for(int w = x; w >= 0; w--) {
      if(prices[i] > w) continue;
      dp[w] = max(dp[w], pages[i]+dp[w-prices[i]]);
    }
  }
  cout << dp[x] << '\n';
}

#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

const int N = 1e5;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> cnt(N+1);
  vector<lli> dp(N+1);
  cnt[0] = 0;
  for (int i = 0; i < n; i++) cnt[arr[i]]++;
  dp[0] = 0;
  dp[1] = cnt[1];
  for (int i = 2; i < N+1; i++)
    dp[i] = max(1LL*dp[i-1], 1LL*dp[i-2] + (1LL*i*cnt[i]));
  cout << dp[N] << '\n';
  return 0;
}


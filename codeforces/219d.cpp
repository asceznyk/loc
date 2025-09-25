#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5+20;

vector<int> dp(N);
vector<vector<pair<int,int>>> adj;

void dfs_zero(int u, int p=-1) {
  for (pair<int,int>& x: adj[u]) {
    int v = x.first, w = x.second;
    if (v == p) continue;
    dfs_zero(v, u);
    dp[0] += w;
  }
}

void dfs_dp(int u, int p=-1) {
  for (pair<int,int>& x: adj[u]) {
    int v = x.first, w = x.second;
    if (v == p) continue;
    dp[v] = dp[u] + (w == 0 ? 1: -1);
    dfs_dp(v, u);
  }
}

int main() {
  int n = 1;
  iostream::sync_with_stdio(false);
  cin >> n;
  int t = n-1;
  dp.resize(n);
  adj.resize(n);
  while (t--) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back({b, 0});
    adj[b].push_back({a, 1});
  }
  dfs_zero(0);
  dfs_dp(0);
  int x_min = *min_element(dp.begin(), dp.end());
  cout << x_min << '\n';
  for (int i = 0; i < n; i++) {
    if (dp[i] != x_min) continue;
    cout << i+1 << " ";
  }
  cout << '\n';
  return 0;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) cin >> grid[i][j];
  }
  vector<vector<ll>> dp(n, vector<ll>(n,0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dp[i][j] = (i-1 >= 0 ? dp[i-1][j] : 0) + (j-1 >= 0 ? dp[i][j-1] : 0);
      if(i+j == 0) dp[i][j] = 1;
      dp[i][j] %= MOD;
      if(grid[i][j] == '*') dp[i][j] = 0;
    }
  }
  cout << dp[n-1][n-1] << endl;
}



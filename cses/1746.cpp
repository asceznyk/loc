#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

const int MOD = (int)1e9 + 7;

using namespace std;

//Recursive, Brute-Force Solution
int solve(vector<int>& nums, int& m, int i) {
  if(i >= (int)nums.size()) return 1;
  if(nums[i] > 0 && abs(nums[i]-nums[i-1]) > 1) return 0;
  if (nums[i] > 0) return solve(nums, m, i+1);
  int x = nums[i-1];
  nums[i] = x;
  int count = solve(nums, m, i+1);
  if(x-1 > 0) {
    nums[i] = x-1;
    count += solve(nums, m, i+1);
  }
  if(x+1 <= m) {
    nums[i] = x+1;
    count += solve(nums, m, i+1);
  }
  nums[i] = 0;
  return count;
}

//DP Solution
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  vector<vector<int>> dp(n,vector<int>(m+1,0));
  int f;
  cin >> f;
  if(f == 0) fill(dp[0].begin()+1, dp[0].end(), 1);
  else dp[0][f] = 1;
  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      for(int k : {x-1,x,x+1}) {
        if(k >= 1 && k <= m) (dp[i][x] += dp[i-1][k]) %= MOD;
      }
      continue;
    } 
    for(int j = 1; j < m+1; j++) {
      for(int k : {j-1,j,j+1}) {
        if(k >= 1 && k <= m) (dp[i][j] += dp[i-1][k]) %= MOD;
      }
    }
  }
  int res = 0;
  for(int j = 0; j < m+1; j++) (res += dp[n-1][j]) %= MOD;
  cout << res << '\n';
  return 0;
}

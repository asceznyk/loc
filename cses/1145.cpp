#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < n; i++) cin >> nums[i];
  vector<int> ans;
  ans.push_back(nums[0]);
  for(int i = 1; i < n; i++) {
    if (ans.back() < nums[i]) ans.push_back(nums[i]);
    else {
      auto low = lower_bound(ans.begin(), ans.end(), nums[i]);
      *low = nums[i];
    }
  }
  cout << ans.size() << endl;
  return 0;
}


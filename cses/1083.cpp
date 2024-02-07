#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n-1);
  for(int i = 0; i < n-1; ++i) cin >> nums[i]; 
  sort(nums.begin(), nums.end());
  int k = 0;
  while(k+1 == nums[k] && k < n-1) k++;
  cout << k+1 << endl;
  return 0;
}


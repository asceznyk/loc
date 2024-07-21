#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> children(n);
  for(int i = 0; i < n; i++) cin >> children[i];
  sort(children.begin(), children.end());
  int gondolas = 0;
  int l = 0, r = children.size()-1;
  while(l < r) {
    if(children[l]+children[r] <= x) l++;
    r--;
    gondolas++;
  }
  cout << gondolas + (int)(l == r) << "\n";
  return 0; 
}


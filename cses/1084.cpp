#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> desired(n);
  for(int i = 0; i < n; i++) cin >> desired[i];
  sort(desired.begin(), desired.end());
  vector<int> apts(m);
  for(int j = 0; j < m; j++) cin >> apts[j];
  sort(apts.begin(), apts.end());
  int count = 0, j = 0;
  for (int i = 0; i < n; i++) {
    int x = desired[i];
    while(j < m) {
      int y = apts[j];
      if(y < x-k) {
        j++;
        continue;
      } else if(abs(x-y) <= k) {
        count++;
        j++;
      }
      break;
    } 
  }
  cout << count << '\n';
  return 0;
}




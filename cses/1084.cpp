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
      if(x-k <= apts[j] && apts[j] <= x+k) {
        count++;
        j++;
        break;
      } else if(apts[j] > x+k) break; 
      else j++;
    } 
  }
  cout << count << '\n';
  return 0;
}




#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> n >> m;
  map<int, int> tickets;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if(tickets.find(t) != tickets.end()) tickets[t]++;
    else tickets[t] = 1;
  };
  for(int i = 0; i < m; i++) {
    int p, k, v;
    cin >> p;
    if(tickets.size() <= 0) {
      cout << -1 << endl;
      continue;
    }
    auto it = tickets.upper_bound(p);
    it--;
    k = (*it).first, v = (*it).second;
    k = (v == 0 || k > p) ? -1 : k;
    cout << k << endl;
    if(k == -1) continue;
    tickets[k]--;
    if(tickets[k] == 0) tickets.erase(k); 
  }
  return 0;
}




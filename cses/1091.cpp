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
    int p;
    cin >> p;
    auto it = tickets.upper_bound(p);
    if(it == tickets.begin()) {
      cout << -1 << "\n";
      continue;
    }
    it--;
    cout << it->first << endl;
    it->second--;
    if(it->second == 0) tickets.erase(it); 
  }
  return 0;
}




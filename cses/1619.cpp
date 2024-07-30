#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; 
  cin >> n;
  map<int,int> timeid;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    timeid[a] = timeid[b] = i;
  }
  set<int> ids;
  int ans = 0, curr = 0;
  for(auto& p: timeid) {
    if(ids.find(p.second) != ids.end()) {
      ids.erase(p.second);
      curr--;
    } else {
      ids.insert(p.second);
      curr++;
    }
    ans = max(ans, curr);
  }
  cout << ans << endl;
  return 0;
}


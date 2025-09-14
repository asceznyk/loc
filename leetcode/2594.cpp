typedef long long ll;

class Solution {
public:
  int numFixable(int r, ll t, vector<ll>& allTimes) {
    int a = 0, b = allTimes.size()-1;
    while (a <= b) {
      int m = (a+b)/2;
      if (r*allTimes[m] > t) b = m-1;
      else a = m+1;
    }
    return a;
  }
  bool areAllFixable(
    ll time,
    vector<int>& ranks, int cars, vector<ll>& allTimes
  ) {
    for (int i = 0; i < ranks.size(); i++) {
      cars -= numFixable(ranks[i], time, allTimes);
      if (cars <= 0) return true;
    }
    return false;
  }
  ll repairCars(vector<int>& ranks, int cars) {
    vector<ll> allTimes(cars);
    for (int t = 1; t <= cars; t++) allTimes[t-1] = 1LL*t*t;
    ll x = 0;
    int r = ranks[ranks.size()-1];
    ll maxRange = 1LL * cars * cars * r;
    for (ll b = maxRange; b >= 1; b /= 2) 
      while(!areAllFixable(x+b, ranks, cars, allTimes)) x += b;
    return x+1;
  }
};


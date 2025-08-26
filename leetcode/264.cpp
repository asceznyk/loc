typedef long long ll;

class Solution {
public:
  int nthUglyNumber(int n) {
    unordered_map<ll,int> mem;
    priority_queue<ll> pq;
    pq.push(-1LL);
    vector<int> primes = {2,3,5};
    ll ans = 1;
    while (!pq.empty()) {
      if (n == 0) break;
      ll x = -1LL*pq.top(); pq.pop();
      ans = x;
      if (mem.find(x) != mem.end()) continue;
      mem[x] = 1;
      n--;
      for (int y: primes) pq.push(-1LL*x*y);
    }
    return static_cast<int>(ans);
  }
};


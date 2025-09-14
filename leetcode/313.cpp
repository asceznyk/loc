typedef long long ll;

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    unordered_map<ll,int> mem;
    priority_queue<ll> pq;
    pq.push(-1LL);
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

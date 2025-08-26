typedef long long ll;

class Solution {
public:
  int nthUglyNumber(int n) {
    unordered_map<ll,int> mem;
    priority_queue<ll> pq;
    pq.push(-1LL);
    vector<int> primes = {2,3,5};
    while (!pq.empty()) {
      if (n == 0) break;
      int x = -1LL*pq.top(); pq.pop();
      if (mem.find(x) != mem.end()) continue;
      mem[x] = 1;
      n--;
      for (int y: primes) pq.push(-1LL*x*y);
    }
    ll ans = 1;
    for (auto& p: mem) ans = max(ans, p.first);
    return static_cast<int>(ans);
  }
};


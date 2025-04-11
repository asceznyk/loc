typedef long long ll;

class Solution {
public:
  ll putMarbles(vector<int>& weights, int k) {
    int n = weights.size();
    if (k == 1 || n == 1) return 0;
    vector<ll> pairWeights(n-1);
    for (int i = 1; i < n; i++) pairWeights[i-1] = weights[i] + weights[i-1];
    sort(pairWeights.begin(), pairWeights.end());
    ll diff = 0;
    for (int i = 0; i < k-1; i++) diff += (pairWeights[n-i-2] - pairWeights[i]);
    return diff;
  }
};



typedef long long ll;

class Solution {
public:
  int maximumCandies(vector<int>& candies, ll k) {
    ll fSum = 0;
    for (int x: candies) fSum += x;
    if (fSum < k) return 0;
    int l = 1, r = *max_element(candies.begin(), candies.end());
    while (l <= r) {
      int m = (l+r)/2;
      ll p = 0;
      for (int x: candies) p += (x/m);
      if (p >= k) l = m+1;
      else r = m-1;
    }
    return l;
  }
};


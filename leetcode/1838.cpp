typedef long long ll;

class Solution {
private:
  ll indexMax(vector<ll>& prefix, vector<int>& nums, ll k, ll i) {
    ll x = nums[i];
    ll l = 0, r = i, m = 0;
    while(l <= r) {
      m = (l+r)/2;
      ll q = ((i-m+1)*x) - (prefix[i] - (m == 0 ? 0 : prefix[m-1]));
      if (q > k) l = m+1;
      else r = m-1;
    }
    return l;
  }
public:
  ll maxFrequency(vector<int>& nums, ll k) {
    sort(nums.begin(), nums.end());
    ll n = nums.size();
    ll p = 0;
    vector<ll> prefix(n, 0);
    for(ll i = 0; i < n; i++) {
      p += nums[i];
      prefix[i] = p;
    }
    p = 0;
    ll maxCount = 1;
    for(ll i = n-1; i > -1; i--) {
      if(nums[i] == p) continue;
      ll currCount = i-indexMax(prefix, nums, k, i)+1;
      p = nums[i];
      maxCount = max(currCount, maxCount);
    };
    printf("ans = %lld\n", maxCount);
    return 0;
  }
};


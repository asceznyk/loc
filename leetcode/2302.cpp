typedef long long ll;

class Solution {
public:
  int n = 0;
  ll countSubarrays(vector<int>& nums, ll k) {
    int n = nums.size();
    vector<ll> prefix;
    ll p = 0LL;
    for(int x: nums) {
      p += x;
      prefix.push_back(p);
    }
    int l = 0, r = 0, off = 0;
    ll ans = 0LL;
    while (r < n) {
      ll score = (prefix[r]-(l > 0 ? prefix[l-1]: 0)) * ((r-l)+1);
      if (score < k) {
        r++;
        off++;
        ans += (1LL*off);
        continue;
      }
      while (l <= r && score >= k) {
        l++;
        score = (prefix[r] - prefix[l-1]) * ((r-l)+1);
        off--;
      }
    }
    return ans;
  }
};


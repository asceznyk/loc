typedef long long ll;

class Solution {
public:
  ll lessThanEqK(int x, vector<int>& nums2, ll p) {
    int m = nums2.size();
    int l = 0, r = nums2.size()-1;
    while (l <= r) {
      int t = (l+r)/2;
      if (1LL*x*nums2[t] > p) {
        if(x < 0) l = t+1;
        else r = t-1;
      } else {
        if (x < 0) r = t-1;
        else l = t+1;
      }
    }
    return 1LL * (x < 0 ? (m-l) : l);
  }
  ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
    ll mRange = 1e10;
    ll l = -1*mRange, r = mRange;
    while (l <= r) {
      ll t = (l+r)/2;
      ll cnt = 0LL;
      for (int i = 0; i < nums1.size(); i++)
        cnt += lessThanEqK(nums1[i], nums2, t);
      if (cnt < k) l = t+1;
      else  r = t-1; 
    }
    return l;
  }
};


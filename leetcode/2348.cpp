typedef long long ll;

class Solution {
public:
  ll zeroFilledSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0;
    ll ans = 0;
    int i = 0;
    while (i < n) {
      ll x = 0;
      while (i < n && nums[i] == 0) {
        x++;
        i++;
      }
      ans += ((x*(x+1))/2);
      i++;
    }
    return 0; 
  }
};



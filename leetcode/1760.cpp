typedef long long int lli;

class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l <= r) {
      int m = (l+r)/2;
      lli ops = 0;
      for (int x: nums) ops += (x-1)/m;
      if (ops > maxOperations) l = m+1;
      else r = m-1;
    }
    return l;    
  }
};


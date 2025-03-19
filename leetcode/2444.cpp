typedef long long ll;

class Solution {
public:
  ll countSubarrays(vector<int>& nums, int minK, int maxK) {
    ll ans = 0, n = nums.size();
    if (minK > maxK) return ans;
    vector<pair<int,int>> goodPairs;
    int i = 0, j = 0;
    for (int k = 0; k < n+1; k++) {
      if (k > n-1 || nums[k] > maxK || nums[k] < minK) {
        goodPairs.push_back({i,j-1});
        i = k+1; j = k+1;
        continue;
      }
      j++;
    }
    if (maxK == minK) {
      for (auto& p: goodPairs) {
        ll x = (p.second-p.first+1);
        ll nsub = ((x*(x+1)/2));
        ans += nsub;
      }
      return ans;
    }
    for (auto& p: goodPairs) {
      i = p.first; j = p.second;
      int l = i, r = i+1;
      while (r < j+1) {
        if ((nums[r] != minK && nums[r] != maxK) || l == r || nums[l] == nums[r]) {
          r++;
          continue;
        }
        if (nums[l] != minK && nums[l] != maxK) {
          l++;
          continue;
        }
        if (nums[l] != nums[r]) {
          ans += (l-i+1)*(j-r+1);
          i = l+1;
          l++;
        }
      }
    }
    return ans;
  }
};


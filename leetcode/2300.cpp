typedef long long ll;

class Solution {
public:
  int lowerBound(vector<int>& potions, ll success, int operand) {
    int low = 0, high = potions.size();
    while (low < high) {
      int mid = (high+low)/2;
      ll search = (ll) potions[mid] * operand;
      if (search >= success) {
        high = mid;
      } else {
        low = mid+1;
      }
    }
    return low;
  }
  vector<int> successfulPairs(
    vector<int>& spells,
    vector<int>& potions,
    ll success
  ) {
    int n = spells.size(), m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> res(n);
    for (int k = 0; k < n; k++) res[k] = m - lowerBound(potions, success, spells[k]);
    return res;
  }
};


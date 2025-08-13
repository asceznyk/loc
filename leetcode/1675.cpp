class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    int ans = INT_MAX;
    set<int> oset;
    for (int x: nums) oset.insert((x % 2 != 0 ? x*2 : x)); 
    int eMax = *--oset.end();
    int eMin = *oset.begin();
    ans = eMax-eMin;
    while (!(eMax % 2)) {
      oset.erase(eMax);
      oset.insert(eMax/2);
      eMax = *--oset.end();
      eMin = *oset.begin();
      ans = min(ans, (eMax-eMin));
    }
    return ans;
  }
};



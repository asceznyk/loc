class Solution {
private:
  bool totalHrs(vector<int>& piles, int k, int h) {
    unsigned int total = 0;
    for(auto p: piles) {
      int res = (p%k) == 0 ? p/k : (p/k)+1;
      total += res;
    }
    return total <= h;
  }
public:
  unsigned int minEatingSpeed(vector<int>& piles, int h) {
    auto z = max_element(piles.begin(), piles.end());
    unsigned int x = 0;
    for(int b = *z; b >= 1; b /= 2) {
      while(!totalHrs(piles, x+b, h)) x += b;
    }
    return x+1;
  }
};

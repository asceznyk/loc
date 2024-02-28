class Solution {
private:
  bool totalHrs(vector<int>& piles, int k, int& h) {
    unsigned int total = 0;
    for(auto p: piles) total += p/k + min(p%k, 1);
    return total <= h;
  }
public:
  unsigned int minEatingSpeed(vector<int>& piles, int h) {
    unsigned int x = 0;
    for(int b = *max_element(piles.begin(), piles.end()); b >= 1; b /= 2) {
      while(!totalHrs(piles, x+b, h)) x += b;
    }
    return x+1;
  }
};

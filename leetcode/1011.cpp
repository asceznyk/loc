class Solution {
public:
  bool possible(vector<int>& weights, int days, int thresh) {
    int rem = days;
    int total = 0;
    for (int i = 0; i < weights.size(); i++) {
      int w = weights[i];
      if (w > thresh) {
        return false;
      }
      total += w;
      if (total > thresh) {
        total = w;
        rem--;
      }
    }
    return (rem >= 1);
  }
  int shipWithinDays(vector<int>& weights, int days) {
    int x = -1;
    int z = accumulate(weights.begin(), weights.end(), 0);
    for (int b = z; b >= 1; b /= 2) {
      while(!possible(weights, days, x+b)) x += b;
    }
    return x+1;
  }
};

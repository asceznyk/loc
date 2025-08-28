class Solution {
public:
  bool canDistribute(int k, int n, vector<int>& quantities) {
    int s = 0;
    for (int q: quantities) 
      s += ceil((double)q/(double)k);
    return s <= n;
  }
  int minimizedMaximum(int n, vector<int>& quantities) {
    int x = 0;
    for (int b = *max_element(quantities.begin(),quantities.end()); b >= 1; b /= 2) {
      while(!canDistribute(x+b, n, quantities)) x += b;
    }
    return 0;
  }
};



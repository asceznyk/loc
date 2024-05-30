class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    if(n <= 2) return 0;
    vector<int> rmaxs(n), lmaxs(n);
    int l = 0, r = 0, w = 0;
    for(int i = 0; i < n; i++) {
      lmaxs[i] = l;
      l = max(l, height[i]);
      rmaxs[n-i-1] = r;
      r = max(r, height[n-i-1]);
    }
    for(int i = 0; i < n; i++) w += max(0, min(lmaxs[i],rmaxs[i])-height[i]);
    return w;
  }
};


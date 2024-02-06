class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    vector<pair<int,int>> vstack;
    for (int i = 0; i < n; i++) {
      int h = heights[i];
      int p = i;
      while (!vstack.empty() && vstack.back().first > h) {
        pair<int,int> x = vstack.back();
        p = x.second;
        maxArea = max(maxArea, max(h*((i-p)+1), x.first*(i-p)));
        vstack.pop_back();
      }
      vstack.push_back({h,p});
    }
    for(auto t: vstack) maxArea = max(maxArea, t.first*(n-t.second));
    return maxArea;
  }
}; 



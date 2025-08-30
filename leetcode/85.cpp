class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<pair<int,int>> vstack;
    for (int i = 0; i < n; i++) {
      int h = heights[i];
      int p = i;
      while (!vstack.empty() && vstack.top().first > h) {
        pair<int,int> x = vstack.top();
        p = x.second;
        maxArea = max(maxArea, max(h*((i-p)+1), x.first*(i-p)));
        vstack.pop();
      }
      vstack.push({h,p});
    }
    while(!vstack.empty()) {
      pair<int,int> p = vstack.top();
      maxArea = max(maxArea, p.first*(n-p.second));
      vstack.pop();
    }
    return maxArea;
  }
  int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> conHeights(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
      int height = 0;
      for (int i = 0; i < m; i++) {
        int curr = matrix[i][j] - '0';
        if (curr == 1) height++;
        else height = 0;
        conHeights[i][j] = height;
      }
    }
    int maxArea = 0;
    for (vector<int>& heights: conHeights)
      maxArea = max(maxArea, largestRectangleArea(heights));
    return maxArea;   
  }
};


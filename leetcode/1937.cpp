typedef long long ll;

class Solution {
public:
  int INF = 1e7;
  int m = 0, n = 0;
  ll maxPoints(vector<vector<int>>& points) {
    m = points.size(), n = points[0].size();
    if (m == 1 && n == 1) return points[0][0];
    ll ans = INF * -1LL;
    vector<ll> currRow(n), nextRow(n), leftMax(n), rightMax(n);
    for (int i = 0; i < n; i++) currRow[i] = points[0][i]*1LL;
    for (int x = 1; x < m; x++) {
      leftMax[0] = currRow[0];
      for (int i = 1; i < n; i++) leftMax[i] = max(currRow[i], leftMax[i-1]-1);
      rightMax[n-1] = currRow[n-1];
      for (int i = n-2; i > -1; i--) rightMax[i] = max(currRow[i], rightMax[i+1]-1);
      for (int i = 0; i < n; i++)
        nextRow[i] = max(leftMax[i], rightMax[i]) + points[x][i]*1LL;
      currRow = nextRow;
    }
    return *max_element(currRow.begin(), currRow.end());
  }
};


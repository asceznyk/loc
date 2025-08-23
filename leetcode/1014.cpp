class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int ans = 0, viMax = values[0];
    for (int j = 1; j < n; j++) {
      viMax = max(values[j-1]+(j-1), viMax);
      ans = max(ans, values[j]-j + viMax);
    }
    return ans;
  }
};


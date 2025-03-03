class Solution {
  public:
  int lengthLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
      if (arr[i] > ans.back()) ans.push_back(arr[i]);
      else {
        int low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
        ans[low] = arr[i];
      }
    }
    return ans.size();
  }
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] != b[0]) return a[0] < b[0];
      return a[1] > b[1];
    });
    for (auto& x: envelopes) printVector(x);
    int n = envelopes.size();
    vector<int> heights(n);
    for (int i = 0; i < n; i++) heights[i] = envelopes[i][1];
    return lengthLIS(heights);
  }
};


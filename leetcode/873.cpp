class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> numSet;
    for (int i = 0; i < n; i++) numSet.insert(arr[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int len = 2;
        int curr = arr[j], prev = arr[i];
        int tsum = curr + prev;
        while (numSet.find(tsum) != numSet.end()) {
          prev = curr;
          curr = tsum;
          tsum = prev + curr;
          len++;
        }
        ans = max(ans, len);
      }
    }
    return (ans == 2) ? 0 : ans;
  }
};


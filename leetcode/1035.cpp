class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> prev(n+1);
    vector<int> curr(n+1);
    for (int i = 1; i < m+1; i++) {
      for(int j = 1; j < n+1; j++) {
        if (nums1[i-1] == nums2[j-1]) curr[j] = 1 + prev[j-1];
        else curr[j] = max(curr[j-1], prev[j]);
      }
      prev = curr;
    }
    return curr[n];
  }
};


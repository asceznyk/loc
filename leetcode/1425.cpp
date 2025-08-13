class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int,int>> maxHeap;
    maxHeap.push({nums[0], 0});
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      while (i - maxHeap.top().second > k) maxHeap.pop();
      int res = nums[i] + max(0, maxHeap.top().first);
      maxHeap.push({res, i});
      ans = max(ans, res);
    }
    return ans;
  }
};


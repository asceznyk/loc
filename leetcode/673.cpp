class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> length(n);
    for (int i = 0; i < n; i++) {
      length[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] >= nums[i]) continue;
        length[i] = max(length[i], length[j]+1);
      }
    }
    vector<int> counts(n, 0);
    counts[0] = 1;
    int maxLis = 0;
    for (int i = 0; i < n; i++) {
      int lis = length[i];
      maxLis = max(lis, maxLis);
      for (int j = 0; j < i; j++) {
        if (length[j] == lis-1 && nums[i] > nums[j]) counts[i] += counts[j];
      }
      counts[i] = max(counts[i], 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if(maxLis == length[i]) ans += counts[i];
    return ans;
  }
};



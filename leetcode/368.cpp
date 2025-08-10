class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> length(n);
    vector<int> parent(n, -1);
    int maxLen = 0, maxIdx = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      length[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
          if (length[j]+1 > length[i]) {
            length[i] = length[j]+1;
            parent[i] = j;
          }
        } 
      }
      if(length[i] > maxLen) {
        maxLen = length[i];
        maxIdx = i;
        res = {nums[i]};
      }
    }
    int x = parent[maxIdx];
    while (x > -1) {
      res.push_back(nums[x]);
      x = parent[x];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

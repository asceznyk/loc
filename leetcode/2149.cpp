class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int pos = -1, neg = -1;
    vector<int> res;
    while (neg < n-1 && pos < n-1) {
      for (int i = pos+1; i < n; i++) {
        if (nums[i] < 0) continue;
        pos = i;
        break;
      }
      for (int i = neg+1; i < n; i++) {
        if (nums[i] > 0) continue;
        neg = i;
        break;
      }
      res.push_back(nums[pos]);
      res.push_back(nums[neg]);
    }
    return res;
  }
};



class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    int vmin = nums[0];
    vector<pair<int,int>> vstack;
    for (int i = 1; i < n; i++) {
      int curr = nums[i];
      while (!vstack.empty()) {
        if (curr < vstack.back().first) break;
        vstack.pop_back();
      }
      if (!vstack.empty()) {
        if(curr > vstack.back().second) return true;
      }
      vstack.push_back({curr, vmin});
      vmin = min(vmin, curr);
    }
    return false;
  }
};

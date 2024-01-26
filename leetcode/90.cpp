class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> ss{};
    vector<vector<int>> pos{};
    sort(nums.begin(), nums.end());
    search(nums, ss, pos, 0);
    return pos;
  }
private:
  void search(
    vector<int>& nums,
    vector<int>& ss,
    vector<vector<int>>& pos,
    int k
  ) {
    if (k >= nums.size()) {
      pos.push_back(ss);
      return;
    }
    ss.push_back(nums[k]);
    search(nums, ss, pos, k+1);
    ss.pop_back();
    while(k+1 < nums.size() && nums[k] == nums[k+1]) k++;
    search(nums, ss, pos, k+1);
  }
};

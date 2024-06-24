class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> p{};
    vector<vector<int>> res{};
    vector<bool> chosen(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrack(nums, chosen, p, res);
    return res;
  }
private:
  void backtrack(
    vector<int>& nums,
    vector<bool>& chosen,
    vector<int>& p,
    vector<vector<int>>& res
  ) {
    if(p.size() == nums.size()) {
      res.push_back(p);
      return;
    }
    int prev = -11;
    for(int i = 0; i < nums.size(); i++) {
      int curr = nums[i];
      if(chosen[i] || prev == curr) continue;
      p.push_back(curr);
      chosen[i] = true;
      backtrack(nums, chosen, p, res);
      p.pop_back();
      chosen[i] = false;
      prev = curr;
    }
  }
};


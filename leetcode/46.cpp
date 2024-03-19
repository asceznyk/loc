class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> p{};
    vector<vector<int>> res{};
    vector<bool> chosen(nums.size(), false);
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
    for(int i = 0; i < nums.size(); i++) {
      if(chosen[i]) continue;
      p.push_back(nums[i]);
      chosen[i] = true;
      backtrack(nums, chosen, p, res);
      p.pop_back();
      chosen[i] = false;
    }
  }
};


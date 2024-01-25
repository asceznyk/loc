class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> comb{};
      vector<vector<int>> res{};
      backtrack(target, candidates, comb, 0, res); 
      return res;
    }
private:
    void backtrack(
        int target,
        vector<int>& candidates,
        vector<int>& comb,
        int i,
        vector<vector<int>>& res
    ) {
      int csum = accumulate(comb.begin(), comb.end(), 0);
      if (csum == target) {
        res.push_back(comb);
        return;
      }
      if (csum > target || i >= candidates.size()) return;
      comb.push_back(candidates[i]);
      backtrack(target, candidates, comb, i, res);
      comb.pop_back();
      backtrack(target, candidates, comb, i+1, res);
    }
};



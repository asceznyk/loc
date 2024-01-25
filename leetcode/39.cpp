class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> comb{};
      vector<int> idxs{};
      vector<vector<int>> res{};
      backtrack(target, candidates, comb, idxs, res); 
      return res;
    }
private:
    void backtrack(
        int target,
        vector<int>& candidates,
        vector<int>& comb,
        vector<int>& idxs,
        vector<vector<int>>& res
    ) {
      int csum = accumulate(comb.begin(), comb.end(), 0);
      if(csum >= target) {
        if (csum == target) res.push_back(comb);
        return;
      }
      for(int i = 0; i < candidates.size(); i++) {
        if(idxs.size() && idxs[idxs.size()-1] > i) continue;
        comb.push_back(candidates[i]);
        idxs.push_back(i);
        backtrack(target, candidates, comb, idxs, res);
        comb.pop_back();
        idxs.pop_back();
      }
    }
};



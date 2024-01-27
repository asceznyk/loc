class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> ss{};
    vector<vector<int>> pos{};
    sort(candidates.begin(), candidates.end());
    vector<int> selected;
    for(auto c: candidates)
      if(c <= target) selected.push_back(c);
    search(selected, target, ss, pos, 0);
    return pos;
  }
private:
  void search(
    vector<int>& selected,
    int target,
    vector<int>& ss,
    vector<vector<int>>& pos,
    int k
  ) {
    if(target == 0) pos.push_back(ss);
    for (int i = k; i < selected.size(); i++) {
      if(i > k && selected[i] == selected[i-1]) continue;
      if(selected[i] > target) break;
      ss.push_back(selected[i]);
      search(selected, target-selected[i], ss, pos, i+1);
      ss.pop_back();
    }
  } 
};

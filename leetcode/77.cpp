class Solution {
private:
  void dfs(vector<vector<int>>& all, vector<int>& sub, int i, int n, int k) {
    if((int)sub.size() == k) {
      all.push_back(sub);
      return;
    }
    for(int j = i+1; j < n+1; j++) {
      sub.push_back(j);
      dfs(all, sub, j, n, k);
      sub.pop_back();
    }
  }
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> all;
    vector<int> sub;
    dfs(all, sub, 0, n, k);
    return all;
  }
};

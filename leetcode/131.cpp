class Solution {
private:
  bool isPalindrome(string& ss) {
    int n = ss.size();
    for(int i = 0; i < n/2; i++) {
      if(ss[i] != ss[n-i-1]) return false;
    }
    return true;
  }
  void  dfs(
    vector<vector<string>>& res, vector<string>& sub,
    int start, string& s
  ) {
    if (start >= s.size()) {
      res.push_back(sub);
      return;
    }
    for(int i = start; i < s.size(); i++) {
      string ss = s.substr(start, (i-start)+1);
      if (!isPalindrome(ss)) continue;
      sub.push_back(ss);
      dfs(res, sub, i+1, s);
      sub.pop_back();
    }
  };
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> sub = {};
    dfs(res, sub, 0, s);
    return res;
  }
};

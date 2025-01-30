class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> vstack;
    vector<int> idxs;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (!vstack.empty() && c == ')') {
        idxs.push_back(vstack.back());
        vstack.pop_back();
      }
      else if(c == '(') {
        vstack.push_back(i);
        idxs.push_back(i);
      }
    }
    map<int,vector<int>> pairIdxs;
    for (int i = 0; i < idxs.size(); i++) pairIdxs[idxs[i]].push_back(i);
    int k = 0, len  = 0, ans = 0;
    while (k < n) {
      if(pairIdxs.find(k) == pairIdxs.end() || pairIdxs[k].size() < 2) {
        k++;
        len = 0;
        continue;
      }
      int l = pairIdxs[k][0], r = pairIdxs[k][1];
      len += r-l+1;
      ans = max(len, ans);
      k += (r-l+1);
    }
    return ans;  
  }
};


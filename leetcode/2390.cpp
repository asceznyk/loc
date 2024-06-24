class Solution {
public:
  string removeStars(string s) {
    vector<char> ts;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '*') ts.pop_back();
      else ts.push_back(s[i]);
    };
    string r = "";
    for(int i = 0; i < ts.size(); i++) r += ts[i];
    return r;
  }
};

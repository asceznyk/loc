class Solution {
public:
  map<char,bool> tMap = {
    {'t',true},
    {'f',false}
  };
  map<bool,string> sMap = {
    {true,"t"},
    {false,"f"}
  };
  bool parseOr(string a) {
    bool res = false;
    for (auto& x: a) res |= tMap[x];
    return res;
  }
  bool parseAnd(string a) {
    bool res = true;
    for (auto& x: a) res &= tMap[x];
    return res;
  } 
  bool parseBoolExpr(string expression) {
    bool ans = false;
    int n = expression.length();
    if (n == 1) 
      return tMap[expression[0]];
    vector<pair<char,string>> funcs;
    for (int i = 0; i < n; i++) {
      char c = expression[i];
      if (c == '(') funcs.push_back({expression[i-1], ""});
      else if (c == ')')  {
        pair t = funcs.back();
        funcs.pop_back();
        char f = t.first;
        string a = t.second;
        bool x = false;
        if (f == '&') x = parseAnd(a);
        else if (f == '|') x = parseOr(a);
        else x = !tMap[a[0]];
        if(!funcs.empty()) funcs[funcs.size()-1].second += sMap[x];
        else ans = x;
      } else if (c == 'f' || c == 't') {
        funcs[funcs.size()-1].second += c;
      } 
    }
    return ans;
  }
};


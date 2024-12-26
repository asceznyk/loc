class Solution {
public:
  string removeKdigits(string num, int k) {
    int n = num.size();
    if (n == k) {
      return "0";
    }
    string ans = "";
    vector<char> vstack;
    for (int i = 0; i < n; i++) {
      char c = num[i];
      while (!vstack.empty() && c-'0' < vstack.back()-'0' && k > 0) {
        vstack.pop_back();
        k--;
      }
      vstack.push_back(c);
    }
    while (k > 0) {
      vstack.pop_back();
      k--;
    }
    int j = 0;
    int m = vstack.size();
    while (j < m-1 && vstack[j]-'0' == 0) j++;
    for (int i = j; i < m; i++) ans += vstack[i];
    return ans;
  }
};


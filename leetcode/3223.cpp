class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    if (n < 3) return n;
    unordered_map<char,int> freq;
    for (int i = 0; i < n; i++) {
      char c = s[i];
      freq[s[i]]++;
    }
    int ans = 0;
    for (auto& item: freq) {
      int count = item.second;
      if (count%2) ans++;
      else ans += 2;
    }
    return ans;
  }
};


class Solution {
public:
  bool checkCounts(vector<int>& c1, vector<int>& c2) {
    for(int i=0; i < c1.size(); i++)
      if(c1[i] != c2[i]) return false;
    return true;
  }
  bool checkInclusion(string s1, string s2) {
    int w = s1.length();
    int n = s2.length();
    vector<int> s1Count(26, 0);
    vector<int> ssCount(26, 0);
    for(auto c: s1) s1Count[(int)c-97]++;
    for(auto c: s2.substr(0, w)) ssCount[int(c)-97]++;
    if(checkCounts(ssCount, s1Count)) return true;
    int p = s2[0];
    for(int i = 1; i <= n-w; i++) {
      string ss = s2.substr(i, w);
      ssCount[p-97]--;
      ssCount[(int)s2[i+w-1]-97]++;
      if(checkCounts(ssCount, s1Count)) return true;
      p = s2[i];
    }
    return false;
  }
};

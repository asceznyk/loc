class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_set<int> ans;
    int m = words.size(), n = s.length(), k = words[0].length();
    int targetLen = m * k;
    map<string,int> targetFreq;
    for (int i = 0; i < m; i++) targetFreq[words[i]]++;
    map<string,int> currFreq;
    for (int i = 0; i < k; i++) {
      currFreq.clear();
      int l = i, r = i+k-1, numWordSS = 0;
      while (l <= r && r < n) {
        int currSSLen = r-l+1;
        string currWord = s.substr(r-k+1, k);
        currFreq[currWord]++;
        if (targetFreq.find(currWord) == targetFreq.end()) {
          r += k;
          l = r-k+1;
          currFreq.clear();
          continue;
        }
        while (currFreq[currWord] > targetFreq[currWord]) {
          string firstWord = s.substr(l,k);
          currFreq[firstWord]--;
          l += k;
          currSSLen -= k;
        }
        if (
          targetLen == currSSLen &&
          targetFreq[currWord] == currFreq[currWord]
        ) ans.insert(l);
        r += k;
      }
    }
    vector<int> out;
    for (int idx: ans) out.push_back(idx);
    return out;
  }
};



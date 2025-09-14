#include "../utils.h"

class Solution {
public:
  int n = 0;
  int inf = 127;
  int countDigits(int x) {
    return ((x == 1) ? 0 : (x < 10 ? 1 : (x < 100 ? 2 : 3)));
  } 
  int dfs(int i, int k, string s, vector<vector<int>>& prefix) {
    if (k < 0) return inf;
    if (i >= n || n-i <= k) return 0;
    int u = s[i]-'a';
    int eLen = dfs(i+1, k, s, prefix);
    if (k == 0) {
      if (i < n-1 && u == s[i+1]-'a') return eLen;
      int j = i;
      while(j >= 0 && u == s[j]-'a') j--;
      return 1 + countDigits(prefix[u][i] - (j >= 0 ? prefix[u][j]: 0)) + eLen;
    }
    int res = eLen;
    if (i == n-k-1 && u == s[i+1]-'a') res = 1 + countDigits(prefix[u][i]) + eLen;
    /*int allPref = 0;
    for (int h = 0; h < 26; h++) {
      if (h == u) continue;
      allPref += prefix[h][i]; 
    }
    if (i == n-1)
    res = min(res, dfs(i+1, k-allPref, s, prefix));*/
    return res;
  }
  int getLengthOfOptimalCompression(string s, int k) {
    printf("s = %s, k = %d\n", s.c_str(), k);
    n = s.length();
    if (n == k) return 0;
    if (n == 1) return 1;
    vector<vector<int>> prefix(26, vector<int>(n));
    for (int h = 0; h < 26; h++) {
      int p = 0;
      for (int i = 0; i < n; i++) {
        int u = s[i]-'a';
        if (u == h) p++;
        prefix[h][i] = p;
      }
    }
    printf("prefix = \n");
    for(auto &v: prefix) printVector(v);
    int ans = dfs(0, k, s, prefix);
    printf("ans = %d\n", ans);
    return ans;
  }
};

int main() {
  Solution sol;
  sol.getLengthOfOptimalCompression("aaaaaaaaaa", 0);
  sol.getLengthOfOptimalCompression("aaabbbaaa", 0);
  sol.getLengthOfOptimalCompression("abccde", 0);
  sol.getLengthOfOptimalCompression("aaaaaaaaaa", 3);
  sol.getLengthOfOptimalCompression("aabbaa", 2);
  return 0;
}

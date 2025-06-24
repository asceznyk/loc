class Solution {
public:
  int uniqueLetterString(string s) {
    int n = s.length();
    vector<int> freq(26);
    vector<vector<int>> indices(26, vector<int>(2, -1));
    vector<bool> seen(26);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int csum = 0;
      int c = s[i] - 'A';
      seen[c] = true;
      if(indices[c][1] == -1) indices[c][1] = i;
      else {
        indices[c][0] = indices[c][1];
        indices[c][1] = i;
      }
      for (int k = 0; k < 26; k++) {
        if (!seen[k]) continue;
        freq[k] += (indices[k][1] - indices[k][0]);
        csum += freq[k];
      }
      ans = csum;
    }
    return ans;   
  }
};

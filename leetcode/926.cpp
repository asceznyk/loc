class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = s.length();
    vector<vector<int>> mem(n+1, vector<int>(2));
    for (int i = n-1; i > -1; i--) {
      for (int prev = 0; prev < 2; prev++) {
        if(prev == 1 && s[i] == '0') {
          mem[i][prev] = 1+mem[i+1][prev];
        } else if(prev == 1 && s[i] == '1') {
          mem[i][prev] = mem[i+1][prev];
        } else {
          int curr = s[i] == '0' ? 0 : 1;
          mem[i][prev] = min(mem[i+1][curr], 1+mem[i+1][curr^1]);
        }
      }
    }
    return mem[0][0];
  }
};


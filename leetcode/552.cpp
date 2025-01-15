typedef long long ll;
const int MOD = 1e9+7;

class Solution {
public:
  int checkRecord(int n) {
    vector<vector<int>> curr(3, vector<int>(4));
    vector<vector<int>> prev(3, vector<int>(4));
    for (int cntA = 0; cntA < 2; cntA++) {
      for (int cntL = 0; cntL < 3; cntL++) prev[cntA][cntL] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int cntA = 1; cntA > -1; cntA--) {
        for (int cntL = 2; cntL > -1; cntL--) {
          ll total = 0;
          total += prev[cntA][0] % MOD;
          total += prev[cntA+1][0] % MOD;
          total += prev[cntA][cntL+1] % MOD;
          curr[cntA][cntL] = (int)(total % MOD);
        }
      }
      prev = curr;
    }
    return curr[0][0];
  }
};


typedef long long ll;
const int MOD = 1e9+7;

class Solution {
public:
  int checkRecord(int n) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(4)));
    for (int cntA = 0; cntA < 2; cntA++) {
      for (int cntL = 0; cntL < 3; cntL++) dp[0][cntA][cntL] = 1;
    }
    for (int i = 1; i < n+1; i++) {
      for (int cntA = 1; cntA > -1; cntA--) {
        for (int cntL = 2; cntL > -1; cntL--) {
          ll total = 0;
          total += dp[i-1][cntA][0] % MOD;
          total += dp[i-1][cntA+1][0] % MOD;
          total += dp[i-1][cntA][cntL+1] % MOD;
          dp[i][cntA][cntL] = (int)(total % MOD);
        }
      }
    }
    return dp[n][0][0];
  }
};


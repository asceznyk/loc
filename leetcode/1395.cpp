class Solution {
public:
  int dfsAsc(
    int i, int t,
    vector<int>& rating, int n,
    vector<vector<int>>& memAsc
  ) {
    if (t == 0) return 1;
    if (i == n) return 0;
    if (memAsc[i+1][t] != -1) return memAsc[i+1][t];
    int cnt = 0;
    for (int j = i+1; j < n; j++) {
      if (i > -1 && rating[j] > rating[i]) continue;
      cnt += dfsAsc(j, t-1, rating, n, memAsc);
    }
    return memAsc[i+1][t] = cnt;
  }
  int dfsDesc(
    int i, int t,
    vector<int>& rating, int n,
    vector<vector<int>>& memDesc
  ) {
    if (t == 0) return 1;
    if (i == n) return 0;
    if (memDesc[i+1][t] != -1) return memDesc[i+1][t];
    int cnt = 0;
    for (int j = i+1; j < n; j++) {
      if (i > -1 && rating[j] < rating[i]) continue;
      cnt += dfsDesc(j, t-1, rating, n, memDesc);
    }
    return memDesc[i+1][t] = cnt;
  }
  int numTeams(vector<int>& rating) {
    int n = rating.size();
    vector<vector<int>> memAsc(n+1, vector<int>(4,-1));
    vector<vector<int>> memDesc(n+1, vector<int>(4,-1));
    int asc = dfsAsc(-1, 3, rating, n, memAsc);
    int desc = dfsDesc(-1, 3, rating, n, memDesc);
    return asc + desc;
  }
};


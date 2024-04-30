int min(int a, int b) {
  return a < b ? a : b;
}

int minDistance(char* word1, char* word2) {
  int m = (int)strlen(word1);
  int n = (int)strlen(word2);
  if(n == 0 || m == 0) return n > m ? n-m : m-n;
  int dp[m+1][n+1];
  for(int i = 0; i < m+1; i++) {
    for(int j = 0; j < n+1; j++) dp[i][j] = 501;
  }
  for(int i = 1; i < m+1; i++) dp[i][0] = i;
  for(int j = 1; j < n+1; j++) dp[0][j] = j;
  dp[0][0] = 0;
  for(int i = 1; i < m+1; i++) {
    for(int j = 1; j < n+1; j++) {
      dp[i][j] = min(
        1+dp[i][j-1],
        min(
          1+dp[i-1][j],
          (int)(word1[i-1] != word2[j-1])+dp[i-1][j-1]
        )
      );
    }
  }
  return dp[m][n];
}


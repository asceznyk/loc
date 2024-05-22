int max(int a, int b) {
  return a > b ? a : b;
}

int longestCommonSubsequence(char* text1, char* text2) {
  int m = strlen(text1);
  int n = strlen(text2);
  int curr[n+1];
  for(int j = 0; j < n+1; j++) curr[j] = 0;
  int prev[n+1];
  for(int j = 0; j < n+1; j++) prev[j] = 0;
  for(int i = 1; i < m+1; i++) {
    for(int j = 1; j < n+1; j++) {
      if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
      else curr[j] = max(prev[j], curr[j-1]);
    }
    for(int j = 0; j < n+1; j++) prev[j] = curr[j]; // prev = curr;
  }
  return curr[n];
};

int characterReplacement(char* s, int k) {
  int n = strlen(s);
  int counts[26] = {0};
  char maxWChar = '-';
  int winSize = 0, maxWLCnt = 0, maxWSize = 0;  
  for(int i = 0; i < n; i++) {
    char c = s[i];
    counts[c-'A']++;
    if(counts[c-'A'] > maxWLCnt) {
      maxWChar = c;
      maxWLCnt = counts[c-'A'];
    }
    winSize++;
    if((winSize - maxWLCnt) > k) {
      winSize--;
      char neg = s[i-winSize];
      counts[neg-'A']--;
      if(neg == maxWChar) maxWLCnt--;
    }
    maxWSize = (winSize > maxWSize) ? winSize : maxWSize;
  }
  return maxWSize;
}

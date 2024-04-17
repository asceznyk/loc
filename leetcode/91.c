int numDecodings(char* s) {
  int n = strlen(s);
  int counts[n+1];
  memset(counts, 0, sizeof(counts));
  counts[n] = 1;
  for(int i = n-1; i > -1; i--) {
    if(*(s+i) == '0') {
      counts[i] = 0;
      continue;
    }
    counts[i] = counts[i+1];
    if(
      *(s+i+1) != '\0' &&
      ((*(s+i)-'0' == 2 && *(s+i+1)-'0' <= 6) || *(s+i)-'0' == 1)
    ) counts[i] += counts[i+2];
  }
  return counts[0];
}

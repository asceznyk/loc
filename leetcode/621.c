int leastInterval(char* tasks, int tasksSize, int n) {
  int counts[26];
  for(int k = 0; k < 26; k++) *(counts+k) = 0;
  int m = 0;
  for(int i = 0; i < tasksSize; i++) {
    counts[tasks[i]-'A']++;
    int c = counts[tasks[i]-'A'];
    m = c > m ? c : m;
  };
  int ans = (n+1)*(m-1);
  for(int i = 0; i < 26; i++)
    if(counts[i] - (m-1) > 0) ans++;
  return (tasksSize > ans ? tasksSize : ans);
}

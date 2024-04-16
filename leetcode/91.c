/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>*/

int countPos(char* s, int i, int* counts) {
  if(*(s+i) == '\0') return 1;
  if(*(s+i) == '0') return 0;
  if(counts[i] != 0) return counts[i];
  counts[i] = countPos(s, i+1, counts);
  if(
    *(s+i+1) != '\0' &&
    ((*(s+i)-'0' == 2 && *(s+i+1)-'0' <= 6) || *(s+i)-'0' == 1)
  ) counts[i] += countPos(s, i+2, counts);
  return counts[i];
}

int numDecodings(char* s) {
  int n = strlen(s);
  int counts[n];
  memset(counts, 0, sizeof(counts));
  int ans = countPos(s, 0, counts);
  printf("ans = %d\n", ans);
  return ans;
}

/*int main() {
  numDecodings("12");
  numDecodings("226");
  numDecodings("11106");
  numDecodings("167");
  numDecodings("3612");
}*/

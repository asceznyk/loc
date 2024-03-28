#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  string sequence;
  cin >> sequence;
  int i = 0, j = 0;
  int lmax = 0;
  int lseq = sequence.length();
  while (i < lseq) {
    while(j < lseq && sequence[i] == sequence[j]) {
      int lcur = j-i+1;
      lmax = max(lcur, lmax);
      j++;
    }
    i = j;
  }
  cout << lmax << endl;
  return 0;
}


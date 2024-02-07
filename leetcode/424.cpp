class Solution {
public:
  int characterReplacement(string s, int k) {
    map<char,int> letterCount;
    int winSize = 0;
    int maxWSize = 0;
    int maxLCnt = 0;
    char maxChar;
    for(int i = 0; i < s.length(); i++) {
      char curr = s[i];
      if(!letterCount.count(curr)) letterCount[curr] = 1; 
      else letterCount[curr]++;
      if(letterCount[curr] > maxLCnt) {
        maxLCnt = letterCount[curr];
        maxChar = curr;
      }
      winSize++;
      int charLeft = winSize - letterCount[maxChar];
      if(charLeft > k) {
        winSize--;
        char neg = s[i-winSize];
        letterCount[neg]--;
        if(neg == maxChar) maxLCnt--;
      }
      maxWSize = max(maxWSize, winSize);
    }
    return maxWSize;
  }
};

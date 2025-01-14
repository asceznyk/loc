class Solution {
public:
  bool checkRecord(string s) {
    int countA = 0;
    for (int i = 0; i < 2; i++) 
      if(s[i] == 'A') countA++;
    if(countA >= 2) return false;
    for (int i = 2; i < (int)s.length(); i++) {
      if (s[i] == 'A') countA++;
      if((s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') || countA >= 2)
        return false;
    }
    return true;
  }
};


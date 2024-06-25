class Solution {
public:
  int maxVowels(string s, int k) {
    string vowels = "aeiou";
    int mcount = 0, wcount = 0;
    for(int i = 0; i < s.length(); i++) {
      if(vowels.find(s[i]) != string::npos) wcount++;
      if(i >= k && vowels.find(s[i-k]) != string::npos) wcount--;
      mcount = max(wcount, mcount);
    };
    return mcount;
  }
};

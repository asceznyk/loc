class Solution {
private:
  int charScore(vector<int>& nfreq, vector<int>& freq, vector<int>& score) {
    int total = 0;
    for (int i = 0; i < 26; i++) {
      total += (nfreq[i]*score[i]);
      if(nfreq[i] > freq[i]) return 0;
    }
    return total;
  }
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int n = words.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < letters.size(); i++) {
      freq[letters[i]-'a']++;
    }
    int maxScore = 0;
    vector<int> nfreq(26, 0);
    for (int i = 0; i < (1 << n); i++) {
      fill(nfreq.begin(), nfreq.end(), 0);
      for (int j = 0; j < n; j++) {
        if(!(i&(1<<j))) continue;
        for (int k = 0; k < words[j].length(); k++) {
          nfreq[words[j][k]-'a']++;
        }
      }
      maxScore = max(maxScore, charScore(nfreq, freq, score)); 
    }
    return maxScore;
  }
};


class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int,int>> ageScores(n);
    for (int i = 0; i < n; i++) {
      ageScores[i].first = ages[i];
      ageScores[i].second = scores[i];
    }
    sort(ageScores.begin(), ageScores.end(), 
    [](const pair<int,int>& a, const pair<int,int>& b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first < b.first; 
    });
    vector<int> scoreSum(n, 0);
    int maxIdx = 0, maxLen = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      scoreSum[i] = ageScores[i].second;
      for (int j = 0; j < i; j++) {
        if (ageScores[j].second <= ageScores[i].second &&
            scoreSum[j] + ageScores[i].second > scoreSum[i]) {
          scoreSum[i] = scoreSum[j] + ageScores[i].second;
        }
      }
      ans = max(scoreSum[i], ans);
    }
    return ans;
  }
};


class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int,int>> capProf(n);
    for (int i = 0; i < n; i++) {
      capProf[i].first = capital[i];
      capProf[i].second = profits[i];
    }
    sort(
      capProf.begin(),
      capProf.end(),
      [](const pair<int,int>& a, const pair<int,int>& b) {
      return a.first < b.first;
    });
    priority_queue<int> pq;
    int l = -1;
    while (k > 0) {
      for (int i = l+1; i < n; i++) {
        if (capProf[i].first > w) break;
        pq.push(capProf[i].second);
        l++;
      }
      if (pq.size() == 0) break;
      w += pq.top();
      pq.pop();
      k--;
    }
    return w;
  }
};


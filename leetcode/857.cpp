class Solution {
public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double,int>> wqRatio;
    for (int i = 0; i < n; i++) {
      double r = (double)wage[i] / (double)quality[i];
      pair<double,int> t = {r, quality[i]};
      wqRatio.push_back(t);
    }
    sort(wqRatio.begin(), wqRatio.end(),
      [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    priority_queue<int> pq;
    int qsum = 0;
    for (int i = 0; i < k; i++) {
      pq.push(wqRatio[i].second);
      qsum += wqRatio[i].second;
    }
    double ans = (wqRatio[k-1].first)*qsum;
    for (int i = k; i < n; i++) {
      double r = wqRatio[i].first;
      int qcurr = wqRatio[i].second;
      qsum += (qcurr-pq.top());
      ans = min(ans, r*(double)qsum);
      pq.pop();
      pq.push(qcurr);
    }
    return ans; 
  }
};


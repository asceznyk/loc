class Solution {
public:
  vector<vector<int>> kSmallestPairs(
    vector<int>& nums1, vector<int>& nums2, int k
  ) {
    int m = nums1.size(),  n = nums2.size();
    auto cmpMax = [](const pair<int,int>& a, const pair<int,int>& b) {
      return (a.first + a.second) < (b.first + b.second);
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmpMax)> \
      pq(cmpMax);
    int i = 0, j = 0;
    bool stop = false;
    while (i < m) {
      while (j < n) {
        if (k == 0) {
          stop = true;
          break;
        };
        pq.push({nums1[i], nums2[j]});
        k--;
        j++;
      }
      if (stop) break;
      j = 0;
      i++;
    }
    while (i < m) {
      auto p = pq.top();
      while (j < n && nums1[i]+nums2[j] < p.first+p.second) {
        pq.pop();
        pq.push({nums1[i], nums2[j]});
        p = pq.top();
        j++;
      }
      j = 0;
      i++;
    }
    vector<vector<int>> res;
    while(!pq.empty()) {
      auto p = pq.top();
      vector<int> t = {p.first, p.second};
      res.push_back(t);
      pq.pop();
    }
    return res;
  }
};

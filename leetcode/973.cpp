class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> triplets;
    for(auto &p: points) triplets.push_back({p[0]*p[0]+p[1]*p[1], p[0], p[1]});
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triplets.begin(), triplets.end());
    vector<vector<int>> res;
    while(k--) {
      vector<int> t = pq.top();
      res.push_back({t[1], t[2]});
      pq.pop();
    }
    return res;
  }
};




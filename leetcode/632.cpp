class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> res = {0, INT_MAX};
    int k = nums.size();
    vector<int> pointers(k);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int curr = nums[0][0], xmax = INT_MIN;
    while (true) {
      if ((int)pq.size() < k) {
        for (int i = 0; i < k; i++) {
          curr = nums[i][pointers[i]];
          xmax = max(xmax, curr);
          pq.push({curr, i});
        }
      }
      auto [xmin, h] = pq.top();
      if((xmax-xmin) < res[1]-res[0]) {
        res[1] = xmax;
        res[0] = xmin;
      }
      pointers[h]++;
      if (pointers[h] == nums[h].size()) break;
      pq.pop();
      curr = nums[h][pointers[h]];
      xmax = max(xmax, curr);
      pq.push({curr, h});
    }
    return res;
  }
};


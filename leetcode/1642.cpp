class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int rsum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    for(i = 0; i < heights.size()-1; i++) {
      if(heights[i+1] <= heights[i]) continue;
      int diff = heights[i+1] - heights[i];
      if((int)pq.size() < ladders) pq.push(diff);
      else if(!pq.empty() && pq.top() < diff) {
        pq.push(diff);
        rsum += pq.top();
        pq.pop();
      } else rsum += diff;
      if(rsum > bricks) break;
    }
    return i;   
  }
};



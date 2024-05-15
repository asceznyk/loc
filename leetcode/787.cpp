typedef priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> MinHeap;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i < (int)flights.size(); i++) {
      vector<int> pflight = flights[i];
      adj[pflight[0]].push_back(pair<int,int>{pflight[1], pflight[2]});
    } 
    vector<vector<pair<int,int>>> dist(n+1);
    for(int i = 0; i < n+1; i++) dist[i].push_back({INT_MAX, INT_MAX});
    dist[src] = {{0,0}};
    MinHeap pq;
    pq.push({0, src, 0});
    while(!pq.empty()) {
      auto [adist, a, astops] = pq.top(); pq.pop();
      if(a == dst) return adist;
      if(astops > k) continue;
      for(auto &[b, w]: adj[a]) {
        int ndist = adist+w, nstops = astops+1;
        if(ndist >= dist[b].back().first && nstops >= dist[b].back().second) continue;
        dist[b].push_back({ndist, nstops});
        pq.push({ndist, b, nstops}); 
      }
    }
    return -1;
  }
};

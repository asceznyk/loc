class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i < (int)times.size(); i++) {
      vector<int> ttime = times[i];
      adj[ttime[0]].push_back(pair<int,int>{ttime[1],ttime[2]});
    } 
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,k});
    while(!pq.empty()) {
      int a = pq.top().second; pq.pop();
      for(int j = 0; j < (int)adj[a].size(); j++) {
        pair<int,int> p = adj[a][j];
        int b = p.first, w = p.second;
        if(dist[a]+w >= dist[b]) continue;
        dist[b] = dist[a]+w;
        pq.push({-dist[b],b});
      }
    };
    int m = 0;
    for(int i = 1; i < n+1; i++) {
      m = max(m, dist[i]);
    }
    return m == INT_MAX ? -1 : m;
  }
};

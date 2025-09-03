class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int steps = 0;
    int n = ring.length(), m = key.length();
    vector<vector<int>> adj(26);
    for (int i = 0; i < n; i++) adj[ring[i]-'a'].push_back(i);
    priority_queue<vector<int>> pq;
    vector<int> t = {0, 0, 0};
    pq.push(t);
    vector<vector<int>> seen(n, vector<int>(m, 0));
    while (!pq.empty()) {
      vector<int> f = pq.top(); pq.pop();
      int d = -f[0], i = f[1], j = f[2];
      if (j == m) {
        steps = d;
        break;
      }
      if (seen[i][j]) continue;
      seen[i][j] = 1;
      for (int k: adj[key[j]-'a']) {
        int between = abs(i-k);
        vector<int> q = {-1*(min(between,n-between)+d), k, j+1};
        pq.push(q);
      }
    }
    return steps + m; 
  }
};



class Graph {
public:
  map<int, vector<pair<int,int>>> adjList;
  int numNodes = 0;
  Graph (int n, vector<vector<int>>& edges) {
    for (auto& edge: edges) {
      int from = edge[0], to = edge[1], cost = edge[2];
      adjList[from].push_back({to, cost});
    }
    numNodes = n;
  }
  void addEdge (vector<int> edge) {
    int from = edge[0], to = edge[1], cost = edge[2];
    adjList[from].push_back({to, cost});
  }
  int shortestPath (int node1, int node2) {
    vector<int> distance(numNodes, INT_MAX);
    distance[node1] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({node1, 0});
    while (!pq.empty()) {
      int a = pq.top().first; pq.pop();
      for (auto& p: adjList[a]) {
        int b = p.first, w = p.second;
        if(distance[a]+w < distance[b]) {
          distance[b] = distance[a]+w;
          pq.push({b, -distance[b]});
        }
      }
    }
    return distance[node2] == INT_MAX ? -1 : distance[node2];
  }
};


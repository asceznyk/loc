class Solution {
private:
  bool visit(vector<int>& processed, vector<int>& nodes, vector<vector<int>>& adj, int n) {
    if (processed[n] == 2) return false;
    if (processed[n] == 1) return true;
    processed[n] = 1;
    for(auto x: adj[n]) { 
      if(visit(processed, nodes, adj, x)) return true;
    } 
    processed[n] = 2;
    nodes.push_back(n);
    return false;
  }
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(int i = 0; i < (int)prerequisites.size(); i++) {
      vector<int> v = prerequisites[i];
      int a = v[0], b = v[1];
      adj[b].push_back(a);
    }
    vector<int> nodes;
    vector<int> processed(numCourses);
    for(int i = 0; i < (int)numCourses; i++) {
      if(processed[i] == 2) continue;
      if(visit(processed, nodes, adj, i)) {
        nodes.clear();
        break;
      };
    }
    reverse(nodes.begin(), nodes.end());
    return nodes;
  }
};

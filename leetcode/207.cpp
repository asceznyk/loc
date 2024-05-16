#include "../utils.h"

class Solution {
private:
  void visit(vector<int>& processed, vector<vector<int>>& adj, int n, bool& r) {
    if (processed[n] == 2) return;
    if (processed[n] == 1) {
      r = false;
      return;
    }
    processed[n] = 1;
    for(auto x: adj[n]) {
      visit(processed, adj, x, r);
    };
    processed[n] = 2;
  }
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(int i = 0; i < (int)prerequisites.size(); i++) {
      vector<int> v = prerequisites[i];
      int a = v[0], b = v[1];
      adj[b].push_back(a);
    }
    bool r = true;
    vector<int> processed(numCourses);
    for(int i = 0; i < (int)numCourses; i++) {
      if(processed[i] == 2) continue;
      visit(processed, adj, i, r);
    }
    return r;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> prerequisites1 = {{1,0}};
  vector<vector<int>> prerequisites2 = {{1,0},{0,1}};
  solve.canFinish(2, prerequisites1);
  solve.canFinish(2, prerequisites2);
  return 0;
}

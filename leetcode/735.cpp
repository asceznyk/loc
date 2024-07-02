class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> pstack, nstack;
    for(int i = 0; i < n; i++) {
      int v = asteroids[i];
      if(v > 0) {
        pstack.push_back(v);
        continue;
      }
      int eq = 0;
      while(!pstack.empty() && abs(v) >= pstack.back()) {
        if(abs(v) == pstack.back()) {
          eq = 1;
          pstack.pop_back();
          break;
        }
        pstack.pop_back();
      };
      if(!eq && pstack.empty()) nstack.push_back(v);
    }
    vector<int> res(nstack.begin(), nstack.end());
    res.insert(res.end(), pstack.begin(), pstack.end());
    return res;
  }
};


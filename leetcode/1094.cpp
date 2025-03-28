#include "../utils.h"

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> population(1001);
    int n = trips.size();
    sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {
      if (a[1] == b[1]) return a[2] < b[2];
      return a[1] < b[1];
    });
    for (int i = 0; i < n; i++) {
      vector<int> trip = trips[i];
      for (int j = trip[1]; j < trip[2]; j++) population[j] += trip[0];
      for (int j = 0; j < population.size(); j++) {
        if (population[j] > capacity) return false;
      }
    }
    return true;
  }
};


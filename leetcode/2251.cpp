class Solution {
public:
  struct CompareVectors {
    bool operator()(const vector<int>& a, const vector<int>& b) {
      if (a[1] != b[1]) return a[1] > b[1];
      return a[0] > b[0];
    }
  };
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    int n = flowers.size(), m = people.size();
    sort(
      flowers.begin(), flowers.end(),
      [](const vector<int>& a, const vector<int>& b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
      }
    );
    vector<vector<int>> doxxed(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
      vector<int> t = {people[i], i};
      doxxed[i] = t;
    }
    sort(
      doxxed.begin(), doxxed.end(),
      [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
      }
    );
    priority_queue<vector<int>, vector<vector<int>>, CompareVectors> minHeap;
    vector<int> numPeople(m);
    int j = 0;
    for (int i = 0; i < m; i++) {
      int curr = doxxed[i][0];
      while (j < n && flowers[j][0] <= curr) {
        if (curr <= flowers[j][1]) minHeap.push(flowers[j]);
        j++;
      }
      while (minHeap.size() > 0) {
        vector<int> oldFlower = minHeap.top();
        if (oldFlower[0] <= curr && curr <= oldFlower[1]) break;
        minHeap.pop();
      }
      numPeople[i] = minHeap.size();
    }
    vector<int> res(m);
    for (int i = 0; i < m; i++) res[doxxed[i][1]] = numPeople[i];
    return res;
  }
};


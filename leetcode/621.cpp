class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> charCount(26, 0);
    int m = 0;
    for(auto c: tasks) {
      charCount[c-'A']++;
      m = max(m, charCount[c-'A']);
    };
    int count = (m-1)*(n+1);
    for(auto y: charCount) if(y == m) count++;
    return max((int)tasks.size(), count);
  }
};


class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> vstack;
    int i = 0, j = 0;
    while (i < n || j < n) {
      if(vstack.empty() || vstack.top() != popped[j]) {
        if(i >= n) break;
        vstack.push(pushed[i]);
        i++;
        continue;
      }
      vstack.pop();
      j++;
    }
    return (i == j);
  }
};


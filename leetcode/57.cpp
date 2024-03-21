class Solution {
private:
  int getIndex(vector<vector<int>>& intervals, int& n, int target, int k) {
    int x = 0;
    if(target >= intervals.back()[k]) return n-1;
    else if(target <= intervals.front()[k]) return 0;
    for(int b = n-1; b >= 1; b /= 2) {
      while(x+b <= n-1 && intervals[x+b][k] <= target) x += b;
    }
    return x;
  }
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    if(n == 0) return vector<vector<int>> {{newInterval[0], newInterval[1]}};
    int a = newInterval[0], b = newInterval[1];
    int start = getIndex(intervals, n, a, 0);
    int end = getIndex(intervals, n, b, 1);
    int i = 0, j = end;
    int gotStart = 0;
    bool abs = false;
    vector<vector<int>> loi;
    while (i <= start) {
      if (a > intervals[i][1]) {
        loi.push_back(intervals[i]);
        gotStart++;
      };
      if (intervals[i][0] <= a && a <= intervals[i][1]) {
        abs = true;
        gotStart = i;
      };
      i++;
    }
    loi.push_back(vector<int> {abs ? min(a, intervals[start][0]) : a});
    int gotEnd = end;
    abs = false;
    while (j <= n-1) {
      if (b < intervals[j][0]) loi.push_back(intervals[j]);
      if (intervals[j][0] <= b && b <= intervals[j][1]) {
        abs = true;
        gotEnd = j;
      };
      j++;
    }
    loi[gotStart].push_back(abs ? max(intervals[gotEnd][1], b) : b);
    return loi;
  }
};


#include "utils.h"

class Solution {
private:
  int getIndex(vector<vector<int>>& intervals, int target, int k) {
    int x = 0;
    if(target >= intervals.back()[1]) return intervals.size()-1;
    else if(target <= intervals.front()[0]) return 0;
    for(int b = intervals.size()-1; b >= 1; b /= 2)
      while(intervals[x+b][k] <= target) x += b;
    return x;
  }
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int a = newInterval[0], b = newInterval[1];
    printf("a = %d, b = %d\n", a, b);
    int start = getIndex(intervals, a, 0);
    int end = getIndex(intervals, b, 1);
    printf("start = %d, end = %d\n", start, end);
    int i = 0, j = end;
    bool abs = false;
    vector<vector<int>> loi;
    while (i <= start) {
      if (a > intervals[i][1]) loi.push_back(intervals[i]);
      if (intervals[i][0] <= a && a <= intervals[i][1]) abs = true;
      i++;
    }
    if(abs) loi.push_back(vector<int> {min(a, intervals[start][0])});
    else loi.push_back(vector<int> {a});
    int got = end;
    abs = false;
    while (j <= intervals.size()-1) {
      if (b < intervals[j][0]) loi.push_back(intervals[j]);
      if (intervals[j][0] <= b && b <= intervals[j][1]) {
        abs = true;
        got = j;
      };
      j++;
    }
    printf("abs = %d\n", abs);
    loi.push_back(abs ? max(intervals[got][1], b) : b);
    for(auto v: loi) printVector(v);
    return loi;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> intervals1 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> newInterval1 = {4,8};
  solve.insert(intervals1, newInterval1);
  vector<vector<int>> intervals2 = {{1,3},{6,9}};
  vector<int> newInterval2 = {2,5};
  vector<int> newInterval3 = {4,10};
  solve.insert(intervals2, newInterval3);
  return 0;
}

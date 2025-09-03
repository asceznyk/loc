class Solution {
public:
  int binarySearch(vector<int>& row, int target) {
    int l = 0, r = row.size()-1;
    while (l <= r) {
      int m = (l+r)/2;
      if (row[m] < target) l = m+1;
      else if (row[m] > target) r = m-1;
      else return m;
    }
    return -1;
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (vector<int>& row: matrix) {
      int res = binarySearch(row, target);
      if (res != -1) return true;
    }
    return false;
  }
};


class Solution {
public:
  int minimumIndex(vector<int>& nums) {
    unordered_map<int,int> freq;
    int d = -1, m = 0;
    for (int x: nums) {
      freq[x]++;
      if (freq[x] > m) {
        m = freq[x];
        d = x;
      }
    }
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      if (x == d) {
        cnt++;
        freq[d]--;
      }
      double leftRatio = static_cast<double>(cnt)/(i+1);
      double rightRatio = static_cast<double>(freq[d])/(n-(i+1));
      if (leftRatio > 0.5 && rightRatio > 0.5) return i;
    }
    return -1;
  }
};


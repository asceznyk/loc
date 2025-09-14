class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size(), rep = 0;
    vector<int> hmap(n+1);
    for (int i = 0; i < n; i++) {
      int curr = nums[i];
      if (hmap[curr] > 0) {
        rep = curr;
      }
      hmap[curr]++;
    }
    int i = 0;
    for (i = 1; i < n+1 && hmap[i] != 0; i++);
    return {rep, i};
  }
};

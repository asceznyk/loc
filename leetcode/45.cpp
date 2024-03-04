// O(n^2)
class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || n == 2) return n-1;
    vector<int> jumps(n, 0);
    for (int i = 0; i < n; i++) {
      jumps[i] = i;
      for (int j = 0; j < i; j++) {
        if(nums[j]+j < i) continue;
        jumps[i] = min(jumps[j]+1, jumps[i]);
      }
    }
    return jumps[n-1];
  }
}

//O(n)
class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if(n == 1 || n == 2) return n-1;
    int jumps = 0, i = 0;
    while (i+nums[i] < n-1) {
      int imax = i+1, vmax = 0;
      for (int j = i+1; j < i+1+ nums[i]; j++) {
        if (nums[j]+j < vmax) continue;
        imax = j;
        vmax = nums[j]+j;
      }
      i = imax;
      jumps++;
    }
    return jumps+1;
  }
};

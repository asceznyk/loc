class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || n == 2) return n-1;
    vector<int> levels(n, 0);
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j <= min(i+nums[i], n-1); j++) {
        if(levels[j] != 0) continue;
        levels[j] = levels[i]+1;
      }
    }
    return levels[n-1];
  }
};

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    set<int> ixt;
    for (int j = 0; j < n; j++) {
      if (j > indexDiff) ixt.erase(nums[j-indexDiff-1]);
      int x = nums[j];
      if (ixt.find(x) == ixt.end()) ixt.insert(x);
      else return true;
      auto next = ixt.find(x);
      auto prev = ixt.find(x);
      advance(next, 1);
      if (next != ixt.end() && abs(x-(*next)) <= valueDiff) return true;
      if (prev != ixt.begin()) {
        advance(prev, -1);
        if (abs(x-(*prev)) <= valueDiff) return true;
      }
    };
    return false;
  }
};



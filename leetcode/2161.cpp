class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> leftS, rightS, mid;
    for (int i = 0; i < n; i++) {
      int curr = nums[i];
      if (curr < pivot) leftS.push_back(curr);
      else if (curr > pivot) rightS.push_back(curr); 
      else mid.push_back(curr);
    }
    vector<int> res;
    res.reserve(leftS.size() + mid.size() + rightS.size());
    res.insert(res.end(), leftS.begin(), leftS.end());
    res.insert(res.end(), mid.begin(), mid.end());
    res.insert(res.end(), rightS.begin(), rightS.end());
    return res;
  }
};


class Solution {
public:
  string intToBinary(int num) {
    string binary;
    while (num > 0) {
      binary = std::to_string(num % 2) + binary; 
      num /= 2;
    }
    return binary.empty() ? "0" : binary;
  }
  string findDifferentBinaryString(vector<string>& nums) {
    int n = nums[0].length();
    set<int> snums;
    for (int i = 0; i < nums.size(); i++)
      snums.insert(stoi(nums[i], nullptr, 2));
    string ans = "";
    for(int b = 0; b < (1 << n); b++) {
      if(snums.find(b) != snums.end()) continue;
      ans = intToBinary(b);
      break;
    }
    string pre = "";
    for (int i = 0; i < n-ans.length(); i++)
      pre += "0";
    ans = pre+ans;
    return ans;
  }
};


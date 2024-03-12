class Solution {
private:
  vector<int> validIdxs(
    vector<vector<int>>& triplets, vector<int> target, vector<int> idxs, int& j
  ) {
    vector<int> tentative;
    bool found = false;
    for(auto i: idxs) {
      if(triplets[i][j] > target[j]) continue;
      tentative.push_back(i);
      if(triplets[i][j] == target[j]) found = true;
    }
    if(!found) tentative.clear();
    return tentative;
  }
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> idxs;
    for(int i = 0; i < triplets.size(); i++) idxs.push_back(i);
    for(int j = 0; j < target.size(); j++) {
      idxs = validIdxs(triplets, target, idxs, j);
      if(idxs.empty()) return false;
    }
    vector<int> cons;
    for(int k = 0; k < 3; k++) cons.push_back(triplets[idxs[0]][k]);
    for(int i = 1; i < idxs.size(); i++) {
      for(int k = 0; k < 3; k++)
        cons[k] = max(cons[k], triplets[idxs[i]][k]); 
    }
    return cons[0] == target[0] && cons[1] == target[1] && cons[2] == target[2];
  }
};

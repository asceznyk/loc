class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int fleet = 0;
    float maxtime = 0.0;
    map<int,float> times;
    for (int i = 0; i < position.size(); i++)
      times[-position[i]] = (float)(target-position[i])/speed[i];
    for (const auto & t: times) {
      if(t.second > maxtime) {
        maxtime = t.second;
        fleet++;
      } 
    }
    return fleet;
  }
};

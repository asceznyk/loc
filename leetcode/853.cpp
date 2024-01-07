#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int fleet = 0;
    float maxTime = 0.0;
    map<int,float> times;
    for (int i = 0; i < position.size(); i++)
      times[-position[i]] = (float)(target-position[i])/speed[i];
    for (const auto & t: times) {
      if(t.second > maxTime) {
        maxTime = t.second;
        fleet++;
      } 
    }
    return fleet;
  }
};

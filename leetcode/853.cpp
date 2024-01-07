#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    int fleet = n;
    float prevTime = 0.0;
    float maxTime = 0.0;
    map<int,int,greater<int>> cars;
    for (int i = 0; i < n; i++) cars.insert({position[i], speed[i]});
    for (const auto & car: cars) {
      float currTime = (float(target)-float(car.first))/float(car.second);
      if(currTime <= maxTime) fleet--; 
      prevTime = currTime;
      if(prevTime > maxTime) { maxTime = prevTime; }
    }
    return fleet;
  }
};

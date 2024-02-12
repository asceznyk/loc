#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) { 
  return a.second < b.second; 
}

vector<pair<string, int>> mapSortByVal(map<string, int>& m) { 
  vector<pair<string, int>> a; 
  for (auto& it : a) 
    a.push_back(it);  
  sort(a.begin(), a.end(), cmp);
  return a;
} 

void printVector(vector<int>& v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}




#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(vector<T>& v) {
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << '\n';
}

template <typename K, typename V>
void printHashMap(map<K,V>& umap) {
  for(auto &it: umap)
    cout << it.first << ": " << it.second << '\n';
}


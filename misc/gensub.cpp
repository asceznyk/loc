#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int>& a) {
  for (auto i: a) {
    cout << i << ",";
  }
  cout << "\n";
}

void search(int k, int n, vector<int>& subset) {
  if (k == n) {
    print_vec(subset);
  } else {
    search(k+1, n, subset);
    subset.push_back(k);
    search(k+1, n, subset);
    subset.pop_back();
  }
}

int main() { 
  int n = 4;
  vector<int> ss;
  search(0, n, ss);
  for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for(int i = 0; i < n; i++) {
      if(b&(1<<i)) subset.push_back(i);
    }
    print_vec(subset);
  }
}


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<long long>& a, int k) {
	sort(a.begin(), a.end());

	vector<long long> psum(a.size()+1, 0);
	for(int i = 0; i < psum.size(); ++i){
		if (i == 0) continue;
		psum[i] = a[i-1] + psum[i-1];
	}

	long long max = 0;
	for(int m = k; m >= 0; --m) { 
		long long s = psum[a.size()-m] - psum[2*(k-m)];
		if (s >= max) max = s;
	}

	cout << max << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;

		vector<long long> a(n, 0);

		for(int i = 0; i < a.size(); ++i) {
			cin >> a[i]; 
		}
		solve(a, k);
	}
}



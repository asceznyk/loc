#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<ll>& a, int k) {
	sort(a.begin(), a.end());

	vector<ll> psum(a.size()+1, 0);
	for(int i = 0; i < psum.size(); ++i){
		if (i == 0) continue;
		psum[i] = a[i-1] + psum[i-1];
	}

	ll max = 0;
	for(int m = k; m >= 0; --m) { 
		ll s = psum[a.size()-m] - psum[2*(k-m)];
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

		vector<ll> a(n, 0);

		for(int i = 0; i < a.size(); ++i) {
			cin >> a[i]; 
		}
		solve(a, k);
	}
}



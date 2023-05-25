#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int dfs(vector<vector<int>>& a, vector<vector<int>>& visited, int i, int j) {
	visited[i][j] = 1;
	int total = a[i][j];

	for (int k = 0; k < 4; k++) {
		int r = i+dirs[k][0];
		int c = j+dirs[k][1];
		if(
				r < 0 || r > a.size()-1 || c < 0 || c > a[0].size()-1 ||
				visited[r][c] == 1 ||
				a[r][c] == 0
		  ) continue;
		total += dfs(a, visited, r, c);
	}

	return total;
}

void solve(vector<vector<int>>& a, vector<vector<int>>& visited) {
	int ans = 0;

	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j < a[0].size(); ++j) {
			if(visited[i][j] || a[i][j] == 0) continue;
			ans = max(ans, dfs(a, visited, i,j));
		}
	}

	cout << ans << endl;
}

void fill_row(vector<int>& row) {
	generate(row.begin(), row.end(), [](){ return rand() % 10; });
}

void fill_matrix(vector<vector<int>>& mat) {
	for_each(mat.begin(), mat.end(), fill_row);
}

void test () {
	for(int t = 0; t < 10000; ++t) {
		int n = rand() % 10 + 1;
		int m = rand() % 10 + 1;

		vector<vector<int>> a(n, vector<int>(m,0));
		vector<vector<int>> visited(n, vector<int>(m,0));

		cout << n << " " << m << endl; 

		fill_matrix(a);
		solve(a, visited);
	}
}

int main() {
	test();

	int t = 1;
	cin >> t;
	while(t--) {
		int n, m;

		cin >> n >> m;

		vector<vector<int>> a(n, vector<int>(m,0));
		vector<vector<int>> visited(n, vector<int>(m,0));

		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j) {
				visited[i][j] = 0; 
				cin >> a[i][j]; 
			}
		}

		solve(a, visited);
	}
}



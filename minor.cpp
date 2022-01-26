#include <bits/stdc++.h>

//#define int long long
//#define mp make_pair
//#define x first
//#define y second
//#define all(a) (a).begin(), (a).end()
//#define rall(a) (a).rbegin(), (a).rend()

typedef long double ld;
typedef long long ll;

using namespace std;

//mt19937 rnd(143);

const int inf = 1e9;
//const int M = 998244353;
//const ld pi = atan2(0, -1);
//const ld eps = 1e-4;

int n, cur;
vector<vector<pair<int, int>>> sl;

void dfs(int v, vector<bool> &used){
    used[v] = true;
    for(auto e: sl[v]){
        int u = e.first, w = e.second;
        if(!used[u] && (cur | w) == cur) {
            cout << v << " -> " << u << " = " << w << "\n";
            dfs(u, used);
        }
    }
}

void cnt(int pw){
    if(pw < 0) return;
    int d = (ll) 1 << pw;    
    cur -= d;

    cout << cur << " " << pw  << "\n";

    vector<bool> used(n); 
    dfs(0, used);

    for(bool b: used) {
        cout << b << " ";
    }
    cout << "\n";

    for(bool b: used){
        if(!b) {
            cur += d;
            break;
        }
    }
    cnt(pw - 1);
}

void print_sl() { 
    for(int v = 0; v < sl.size(); ++v) {
        cout << "\n";
        for(auto e: sl[v]) {
            int u = e.first, w = e.second;
            cout << u << ", " << w << "\n";
        }
    }

    cout << "\n";
}

void solve() {
    int m;
    cin >> n >> m;
    sl.assign(n, vector<pair<int, int>>(0));
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        sl[u].emplace_back(v, w);
        sl[v].emplace_back(u, w);
    }

    print_sl();

    cur = 1;
    int bit = 0;
    for(; cur < inf; bit++){
        cur = 2 * cur + 1;
    }
    cnt(bit);
    cout << cur;
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi) {
        cin >> t;
    }

    cout << "\n";

    for (; t != 0; --t) {
        solve();
        cout << "\n";
    }
    return 0;
}


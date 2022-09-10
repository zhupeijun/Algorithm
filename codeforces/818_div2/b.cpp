#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vc<vi>;

void solve() {
    int n, k, r, c; cin >> n >> k >> r >> c;
    rep(i, n) {
        rep(j, n) {
            if (abs(i+j-r-c+2) % k == 0) cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
}

int main() {
    int T; cin >> T;
    rep(t, T) solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
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
using vvi = vv<int>;

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi b(n); rep(i, n) cin >> b[i];

    vi p(n); rep(i, n) p[b[i]/2-1] = i;
    int minv = p[n-1]; 
    FR(i, n-2, 0) { mins(minv, p[i]); p[i] = minv; }

    int ans = n*2;
    rep(i, n) mins(ans, p[a[i]/2]+i);

    cout << ans << endl;
}

int main() {
    int T; cin >> T;
    rep(i, T) solve();
    return 0;
}
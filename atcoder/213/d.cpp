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
using G = vvi;

void dfs(G& g, int u, int fa, vi& r) {
    r.pb(u);
    each(g[u], v) {
        if (v != fa) {
            dfs(g, v, u, r);
            r.pb(u);
        }
    }
}

int main() {
    int N; cin >> N;
    G g(N);
    rep(i, N-1) {
        int x, y; cin >>x>>y; --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    each(g, v) sort(rng(v));

    vi r;
    dfs(g, 0, -1, r);

    int m = sz(r);
    rep(i, m) cout << (r[i]+1) << (i == m-1 ? "\n" : " ");
    return 0;
}
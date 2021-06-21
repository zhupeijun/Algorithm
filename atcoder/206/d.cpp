#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define each(v, i) for (auto& i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()
#define in(a, x) a.find(x) != a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;

int N;

int dfs(int u, map<int, vi>& g, set<int>& vis) {
    if (in(vis, u)) return 0;
    vis.insert(u);
    int ret = 1;
    each(g[u], v) ret += dfs(v, g, vis);
    return ret;
}

int main() {
    cin >> N;
    vi a(N); rep(i, N) cin >> a[i];
    int i = 0, j = N-1;
    map<int, vi> g;
    while (i < j) {
        if (a[i] != a[j]) {
            g[a[i]].pb(a[j]);
            g[a[j]].pb(a[i]);
        }
        ++i; --j;
    }

    set<int> vis;
    int ans = 0;
    for (const auto& p : g) {
        if (in(vis, p.fi)) continue;
        ans += dfs(p.fi, g, vis) - 1;
    }
    cout << ans << endl;
    return 0;
}
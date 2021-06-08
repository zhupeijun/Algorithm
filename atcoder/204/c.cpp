#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = max(x, y)
#define pcnt __builtin_popcount

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int dfs(int u, vvi& g, vi& vis) {
    vis[u] = 1;
    int ret = 0; 
    each(g[u], v) {
        if (!vis[v]) {
            ret += dfs(v, g, vis);
        }
    }
    return ret + 1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vvi g(N, vi(0));
    rep(i, M) {
        int A, B;
        cin >> A >> B; --A; --B;
        g[A].pb(B);
    }

    int ans = 0;
    rep(u, N) {
        vi vis(N, 0);
        int ret = dfs(u, g, vis);
        ans += ret;
    }
    cout << ans << endl;
    return 0;
}
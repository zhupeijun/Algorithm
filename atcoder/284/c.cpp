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
using G = vc<vi>;

int main() {
    int N, M; cin >> N >> M;
    G g = G(N);
    rep(i, M) {
        int u, v; cin >> u >> v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }

    vc<bool> vis(N);
    int ans = 0;
    rep(i, N) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i); vis[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
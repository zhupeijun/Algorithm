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
    G g(N);
    vi d(N);
    rep(i, M) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].pb(b);
        g[b].pb(a);
        ++d[a]; ++d[b];
    }

    each(d, v) {
        if (v > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    queue<int> q;
    vc<bool> vis(N);
    rep(i, N) if (d[i] <= 1) {
        q.push(i);
        vis[i] = true;
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ++cnt;
        for (int v : g[u]) {
            if (vis[v]) continue;
            --d[v];
            if (d[v] <= 1) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    if (cnt == N) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
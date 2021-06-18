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
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vl = vc<ll>;
using vb = vc<bool>;

struct E {
    int v, c, d;
    E(int v, int c, int d) : v(v), c(c), d(d) { }
};

using G = vc<vc<E>>;
using pl = pair<ll, ll>;
using Q = priority_queue<pl, vc<pl>, greater<pl>>; 

int N, M;
const ll INF = 1000000000000005ll;

int main() {
    cin >> N >> M;
    G g(N);
    rep(i, M) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        --u; --v;
        g[u].pb(E(v, c, d));
        g[v].pb(E(u, c, d));
    }

    Q q; q.push(mp(0, 0));
    vl dist(N, INF); dist[0] = 0;
    vb vis(N, false);
    while (!q.empty()) {
        pl x = q.top(); q.pop();
        if (vis[x.se]) continue;
        vis[x.se] = true;
        each(g[x.se], e) {
            if (vis[e.v]) continue;
            ll t = ceil(sqrt(e.d)-1);
            maxs(t, x.fi);
            ll nt = t + e.d/(t+1) + e.c;
            if (dist[e.v] > nt) {
                dist[e.v] = nt;
                q.push(mp(nt, e.v));
            }
        }
    }
    if (dist[N-1] == INF) dist[N-1] = -1;
    cout << dist[N-1] << endl;
    return 0;
}
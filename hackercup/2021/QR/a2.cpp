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
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using G = vc<vc<int>>;

const int M = 26;
const int INF = 200;

void solve() {
    string S; cin >> S;
    int K; cin >> K;
    
    G g = G(M);
    rep(i, K) {
        string p; cin >> p;
        int x = p[0] - 'A', y = p[1] - 'A';
        g[x].pb(y);
    }

    vc<vi> dis(M, vi(M, INF));
    rep(k, M) {
        vc<bool> vis(M, false);
        queue<pi> q; q.push(mp(k, 0)); vis[k] = true;
        while (!q.empty()) {
            pi t = q.front(); q.pop();
            int u = t.fi, d = t.se;
            dis[k][u] = d;
            each(g[u], v) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(mp(v, d+1));
                }
            }
        }
    }

    int ans = -1;
    rep(x, M) {
        int d = 0;
        each(S, c) {
            int y = c - 'A';
            int cost = dis[y][x];
            if (cost == INF) {
                d = -1;
                break;
            } else {
                d += cost;    
            }
        }
        if (d != -1) {
            if (ans == -1) ans = d;
            else mins(ans, d);
        }
    }
    cout << ans << endl;
}

int main() {
    int T; cin >>T;
    rep(i, T) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
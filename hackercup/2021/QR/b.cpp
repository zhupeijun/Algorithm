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
#define ts to_string
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using G = vc<string>;

void solve() {
    int N; cin >> N;
    G g(N); rep(i, N) cin >> g[i];

    int len = -1;
    set<vc<pi>> w;
    rep(i, N) {
        vc<pi> s;
        bool ok = true;
        rep(j, N) {
            if (g[i][j] == 'O') { ok = false; break; } 
            else if (g[i][j] == '.') s.pb(mp(i, j));
        }

        if (ok) {
            if (len == -1 || len > sz(s)) { 
                w.clear(); w.insert(s); len = sz(s); 
            } else if (len == sz(s)) { 
                w.insert(s);
            }
        }
    }

    rep(j, N) {
        vc<pi> s;
        bool ok = true;
        rep(i, N) {
            if (g[i][j] == 'O') { ok = false; break; }
            else if (g[i][j] == '.') s.pb(mp(i, j));
        }

        if (ok) {
            if (len == -1 || len > sz(s)) { 
                w.clear(); w.insert(s); len = sz(s); 
            } else if (len == sz(s)) { 
                w.insert(s);
            }
        }
    }

    if (len == -1) cout << "Impossible" << endl;
    else cout << (sz(*(w.begin()))) << " " << sz(w) << endl;
}

int main() {
    int T; cin >> T;
    rep(i, T) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
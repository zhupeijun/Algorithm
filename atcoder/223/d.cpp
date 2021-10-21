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
using G = vv<int>;
using Q = priority_queue<int,vi,greater<int>>;

int main() {
    int N, M; cin >> N >> M;
    G g(N); vi d(N);
    rep(i, M) {
        int A, B; cin >> A >> B;
        --A; --B;
        g[A].pb(B);
        d[B]++;
    }

    vi ans; Q q;
    rep(i, N) if (d[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.top(); q.pop();
        ans.pb(u);
        each(g[u], v) {
            --d[v];
            if (d[v] == 0) q.push(v);
        }
    }
    if (sz(ans) == N) {
        rep(i, N) cout << ans[i] + 1 << (i==N-1?"\n":" ");
    } else {
        cout << -1 << endl;
    }
    return 0;
}
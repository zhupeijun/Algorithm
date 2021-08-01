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
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vp = vc<pi>;

int main() {
    int N; cin >> N;
    vi a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    set<int> ans;
    rep(i, N) {
        unordered_map<int, int> c;
        rep(j, N) ++c[b[j]];

        int v = a[0]^b[i];
        
        bool ok = true;
        FF(i, 1, N-1) {
            int x = v^a[i];
            if (c[x] > 0) --c[x];
            else { ok = false; break; }
        }
        if (ok) ans.insert(v);
    }
    cout << sz(ans) << endl;
    each(ans, x) cout << x << endl;
    return 0;
}
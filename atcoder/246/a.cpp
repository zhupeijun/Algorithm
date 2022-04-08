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

int main() {
    vc<pi> a;
    rep(i, 3) {
        int x, y; cin >> x >> y;
        a.pb(mp(x,y));
    }

    int x1 = min(a[0].fi, min(a[1].fi, a[2].fi));
    int x2 = max(a[0].fi, max(a[1].fi, a[2].fi));
    int y1 = min(a[0].se, min(a[1].se, a[2].se));
    int y2 = max(a[0].se, max(a[1].se, a[2].se));

    vc<pi> all = { mp(x1, y1), mp(x1, y2), mp(x2, y1), mp(x2, y2) };
    for (auto& p : all) {
        bool exist = false;
        for (auto &q : a) {
            if (p == q) { exist = true; break; }
        }

        if (!exist) {
            cout << p.fi << " " << p.se << endl;
            break;
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define find(a, v) a.find(v) != a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int main() {
    int N, M; cin >> N >> M;
    map<int,vi> m;
    rep(i, M) {
        int x, y; cin >> x >> y;
        m[x].pb(y);
    }

    set<int> s = { N };
    each(m, p) {
        vi ad, rm;
        each(p.se, v) {
            if (s.count(v)) rm.pb(v);
            if (s.count(v+1)) ad.pb(v);
            if (s.count(v-1)) ad.pb(v);
        }
        each(rm, v) s.erase(v);
        each(ad, v) s.insert(v);
    }
    cout << sz(s) << endl;
    return 0;
}
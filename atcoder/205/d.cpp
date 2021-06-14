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
#define rng(a) a.begin(), a.end()
#define pcnt __builtin_popcount

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;

const ll MAX = 2000000000000000000ll;

int main() {
    int N, Q; cin >> N >> Q;
    vl a; a.pb(0); a.pb(MAX);
    rep(i, N) { ll x; cin >> x; a.pb(x); }
    sort(rng(a));

    map<ll, ll> r;
    ll cnt = 1;
    for (int i = 0; i < sz(a)-1; ++i) {
        ll d = a[i+1] - a[i] - 1;
        if (d > 0) {
            r[cnt] = a[i]+1;
            cnt += d;
        }
    }

    while (Q--) {
        ll K; cin >> K;
        auto it = r.upper_bound(K);
        --it;
        ll add = K - it->fi;
        cout << it->se + add << endl;
    }
    
    return 0;
}
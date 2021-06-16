#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define mp make_pair
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using pll = pair<ll, ll>;
using vp = vc<pll>;

int main() {
    ll N, K; cin >> N >> K;
    vp a; 
    rep(i, N) {
        ll A, B; cin >> A >> B;
        a.pb(mp(A, B));
    } 

    sort(rng(a));

    ll cur = 0;
    each(a, p) {
        ll need = p.fi - cur;
        if (K - need < 0) break;
        else {
            cur = p.fi;
            K = K - need + p.se;
        }
    }

    cout << cur + K << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, n) for (int i=(n-1); i>=0; --i)
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

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int main() {
    int N,K,X; cin >>N>>K>>X;
    vi a(N); rep(i, N) cin >> a[i];

    rep(i, N) {
        int use = min(K, a[i] / X);
        a[i] -= use * X; K -= use;
    }

    sort(rng(a));
    repr(i, N) if (a[i] > 0 && K > 0) {
        a[i] = 0; --K;
    }
    
    ll ans = 0;
    for (int x : a) ans += x;
    cout << ans << endl;
    return 0;
}
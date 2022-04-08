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

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

ll cal(ll a, ll b) {
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    ll N; cin >> N;

    ll ans = LONG_LONG_MAX;
    rep(a, 1000000) {
        int l = 0, r = 1000000;
        while (l <= r) {
            int mid = (l+r) >> 1;
            ll val = cal(a, mid);
            if (val >= N) r = mid-1;
            else l = mid+1;
        }
        mins(ans, cal(a, l));
    }
    cout << ans << endl;
    return 0;
}
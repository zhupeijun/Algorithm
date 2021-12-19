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

int main() {
    int N, Q; cin >> N >> Q;
    vi a(N); rep(i, N) cin >> a[i];
    sort(rng(a));
    rep(i, Q) {
        int x; cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        int ans = distance(it, a.end());
        cout << ans << endl;
    }
    return 0;
}


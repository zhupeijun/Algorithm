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

void solve() {
    int n; scanf("%d", &n);
    vi a(n); rep(i, n) scanf("%d", &a[i]);
    sort(rng(a));

    int cur = 1, ans = 0;
    rep(i, n) {
        if (a[i] >= cur) {
            ++ans;
            ++cur;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; cin >> T;
    rep(i, T) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
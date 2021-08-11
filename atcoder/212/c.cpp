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
    int N, M; cin >>N>>M;
    vi a(N), b(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];

    sort(rng(a));
    sort(rng(b));

    int ans = INT_MAX;
    each(a, v) {
        auto it = lower_bound(rng(b), v);
        if (it != b.end()) {
            if (it == b.begin()) {
                mins(ans, abs(*it - v));
            } else {
                mins(ans, abs(*it - v));
                --it; 
                mins(ans, abs(*it - v));
            }
        } else {
            --it;
            mins(ans, abs(*(it) - v));
        }
    }
    cout << ans << endl;
    return 0;
}
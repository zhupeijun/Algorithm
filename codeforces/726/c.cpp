#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repa(i, a, n) for (int i=a; i<(n); ++i)
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

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    sort(rng(a));
    int minv = INT_MAX, mini = 0;
    if (n > 2) {
        repa(i, 1, n) {
            int v = a[i] - a[i-1];
            if (v < minv) {
                minv = v;
                mini = i;
            }
        }
    }

    bool first = true;
    repa(i, mini, n) {
        if (first) first = false;
        else cout << " ";
        cout << a[i];
    }

    rep(i, mini) {
        if (first) first = false;
        else cout << " ";
        cout << a[i];
    }

    cout << endl;
}

int main() {
    int T; cin >> T;
    rep(i,T) solve();
    return 0;
}
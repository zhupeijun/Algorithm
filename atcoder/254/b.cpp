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
    int n; cin >> n;
    vi a(n+5); a[0] = 1;
    rep(i, n) {
        rep(j, i+1) cout << a[j] << (j == i ? '\n' : ' ');
        for (int j = i+1; j > 0; --j) a[j] += a[j-1];
    }

    return 0;
}
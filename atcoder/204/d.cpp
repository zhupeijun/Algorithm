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

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int main() {
    int M = 100005;
    int N; cin >> N;
    vi T(N); rep(i, N) cin >> T[i];
    vc<bool> a(M, false); a[0] = true;
    int sum = 0; rep(i, N) sum += T[i];
    rep(i, N) {
        vc<bool> tmp(M, false);
        rep(j, M) {
            if (a[j]) {
                tmp[j] = true;
                tmp[j+T[i]] = true;
                tmp[T[i]] = true;
            }
        }
        a = tmp;
    }
    int ans = INT_MAX;
    rep(j, M) {
        if (a[j]) {
            int o = sum - j;
            mins(ans, max(o, j));
        }
    }
    cout << ans << endl;
    return 0;
}
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
using vvi = vv<int>;

void solve() {
    int N, M, A, B;
    cin>>N>>M>>A>>B;
    int tot = N+M-1;
    if (A < tot || B < tot) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        vvi a(N, vi(M, 1));
        a[N-1][M-1] = A - (tot-1);
        a[N-1][0] = B - (tot-1);

        rep(i, N) rep(j, M) {
            cout << a[i][j] << (j==M-1?"\n":" ");
        }
    }
}

int main() {
    int T; cin>>T;
    rep(i, T) {
        cout << "Case #"<<(i+1)<<": ";
        solve();
    }
    return 0;
}
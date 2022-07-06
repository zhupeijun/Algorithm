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

double dist(int x1, int y1, int x2, int y2) {
    double dx = x1-x2, dy = y1-y2;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    int N, K; cin >> N >> K;
    vi A(K); rep(i, K) cin >> A[i];
    vi X(N), Y(N); rep(i, N) cin >> X[i] >> Y[i];

    double ans = 0;
    rep(i, N) {
        double d = 8e18;
        rep(j, K) mins(d, dist(X[i], Y[i], X[A[j]-1], Y[A[j]-1]));
        maxs(ans, d);
    }
    printf("%.12lf\n", ans);
    return 0;
}
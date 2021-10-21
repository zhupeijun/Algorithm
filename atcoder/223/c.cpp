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
    int N; cin >> N;
    vi A(N), B(N); rep(i, N) cin >> A[i] >> B[i];

    double tot = 0;
    rep(i, N) tot += (double)A[i]/B[i];

    double half = tot / 2;
    double cur = 0;
    double ans = 0;
    rep(i, N) {
        double t = (double)A[i]/B[i];
        if (cur + t < half) {
            cur += t;
            ans += A[i];
        } else {
            double rm = half - cur;
            ans += B[i] * rm;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
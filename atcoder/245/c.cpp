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
using vb = vc<bool>;

int main() {
    int N, K; cin >> N >> K;
    vi A(N); rep(i, N) cin >> A[i];
    vi B(N); rep(i, N) cin >> B[i];

    vb oka(N, false), okb(N, false);
    rep(i, N) {
        if (i == 0) {
            oka[i] = okb[i] = true;
        } else {
            if (oka[i-1]) {
                if (abs(A[i]-A[i-1]) <= K) oka[i] = true;
                if (abs(B[i]-A[i-1]) <= K) okb[i] = true;
            } 

            if (okb[i-1]) {
                if (abs(A[i]-B[i-1]) <= K) oka[i] = true;
                if (abs(B[i]-B[i-1]) <= K) okb[i] = true;
            }
        }
    }

    cout << (oka[N-1] || okb[N-1] ? "Yes" : "No") << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef unordered_set<int> us;

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

#define R(N, X) int N; cin >> N; vi X(N); rep(i, N) cin >> X[i];

int main() {
    R(N, A); R(M, B); R(L, C); R(Q, X);

    us s;
    rep(i, N) rep(j, M) rep(k, L) {
        s.insert(A[i]+B[j]+C[k]);
    }

    rep(i, Q) {
        if (s.find(X[i]) != s.end()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
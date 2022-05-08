#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
#define pb push_back
#define eb emplace_back
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

int cal(int A, int B, int C, int X) {
    int d = 0, t = 0;
    while (X > 0) {
        int t = min(X, A);
        d += t*B; X -= t;
        X -= min(X, C);
    }
    return d;
}

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int d1 = cal(A, B, C, X);
    int d2 = cal(D, E, F, X);   
    if (d1 > d2) cout << "Takahashi" << endl;
    else if (d1 < d2) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vp = vc<pi>;

int main() {
    int N; cin >> N;
    vp a;
    rep(i, N) {
        int x; cin >> x;
        a.pb(mp(x, i+1));
    }
    sort(rng(a));
    cout << a[N-2].se << endl;
    return 0;
}
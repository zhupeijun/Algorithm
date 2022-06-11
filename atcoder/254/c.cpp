#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, s, n) for(int i=(s);i<(n);++i)
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
    int N, K; cin >> N >> K;
    vi v(N); rep(i, N) cin >> v[i];
    
    vi t, ans(N);
    rep(j, K) {
        for(int i = j; i < N; i+=K) t.pb(v[i]);
        sort(rng(t));
        for (int i = j, k = 0; i < N; i+=K, ++k) ans[i] = t[k];
        t.clear();
    }

    rep(i, N-1) {
        if (ans[i] > ans[i+1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
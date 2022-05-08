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

int main() {
    int N; cin >> N;
    vi A(N); rep(i, N) cin >> A[i];

    unordered_map<int,int> cnt;
    unordered_set<int> S(rng(A));
    each(A, x) ++cnt[x];

    ll ans = 0;
    each(S, v) {
        int x = 1;
        while (x*x <= v) {
            if (v%x == 0) {
                int y = v/x;
                if (x == y) {
                    ans += (ll)cnt[v]*cnt[x]*cnt[x];
                } else {
                    ans += (ll)cnt[v]*cnt[x]*cnt[y]*2;
                }
            }
            ++x;
        }
    }
    cout << ans << endl;
    return 0;
}
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
    int N, K; cin >> N >> K;
    vector<string> S(N); rep(i, N) cin >> S[i];
    int M = 1 << N;
    int ans = 0;
    rep(m, M) {
        vector<int> cnt(26, 0);
        rep(i, N) {
            if ((1<<i)&m) {
                vector<bool> ext(26, false);
                each(S[i], v) {
                    ext[v-'a'] = true;
                }
                rep(k, 26) if (ext[k]) ++cnt[k];
            }
        }

        int alp = 0;
        rep(i, 26) {
            if (cnt[i] == K) ++alp;
        }
        maxs(ans, alp);
    }
    cout << ans << endl;
    return 0;
}
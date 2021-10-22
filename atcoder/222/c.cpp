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

struct S {
    int i, w;
    S(int i, int w) : i(i), w(w) { }
    bool operator < (const S& o) const {
        if (w == o.w) return i < o.i;
        return w > o.w;
    }
};

map<string, int> R = {
    {"GC", 1},
    {"GP", -1},
    {"GG", 0},
    {"CG", -1},
    {"CP", 1},
    {"CC", 0},
    {"PG", 1},
    {"PC", -1},
    {"PP", 0}
};

int main() {
    int N, M; cin >> N >> M;
    int T = N*2;
    vc<S> s; rep(i, T) s.pb(S(i, 0));
    vc<string> C(T); rep(i, T) cin>>C[i];
    rep(i, M) {
        for (int j = 0; j < T; j+=2) {
            int k1 = s[j].i, k2 = s[j+1].i;
            string p = string{C[k1][i]} + C[k2][i];
            int val = R[p];

            if (val > 0) s[j].w++;
            else if (val < 0) s[j+1].w++;
        }
        sort(rng(s));
    }
    rep(i, T) cout << s[i].i + 1 << endl;
    return 0;
}
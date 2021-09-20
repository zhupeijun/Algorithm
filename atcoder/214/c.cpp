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
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;

int main() {
    int N; cin >> N;
    vi S(N); rep(i, N) cin>>S[i];
    vi T(N); rep(i, N) cin>>T[i];

    priority_queue<pi, vector<pi>,greater<pi>> q;
    rep(i, N) q.push(mp(T[i], i));
    vi ans(N, -1);
    while (!q.empty()) {
        pi t = q.top(); q.pop();
        int i = t.se, tm = t.fi;
        if (ans[i] == -1) {
            ans[i] = tm;
            q.push(mp(tm+S[i], (i+1)%N));
        }
    }
    rep(i, N) cout << ans[i] << endl;
    return 0;
}
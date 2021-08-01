#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repx(i, x, n) for(int i=x;i<(n);++i)
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

ll a[2005][2];

int main() {
    int N; cin >> N;
    rep(i, N) {
        int t; cin >> t;
        cin >> a[i][0] >> a[i][1];
        a[i][0] *= 10; a[i][1] *= 10;
        if (t == 2 || t == 4) --a[i][1];
        if (t == 3 || t == 4) ++a[i][0];
    }

    int ans = 0;
    rep(i, N) repx(j, i+1, N) {
        if (a[i][0] > a[j][1] || a[i][1] < a[j][0]) continue;
        ++ans;
    }

    cout << ans << endl;
    return 0;
}
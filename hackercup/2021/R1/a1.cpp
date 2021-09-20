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

int cal(bool left, const string& W) {
    int ret = 0;
    each(W, x) {
        if (x == 'O') {
            if (!left) { left = true; ++ret; }
        } else if (x == 'X') {
            if (left) { left = false; ++ret; }
        }
    }
    return ret;
}

void solve() {
    int N; cin>>N;
    string W; cin>>W;
    int ans = min(cal(true, W), cal(false, W));
    cout << ans << endl;
}

int main() {
    int T; cin >>T;
    rep(i, T) {
        cout << "Case #"<< (i+1) << ": ";
        solve();
    }
    return 0;
}